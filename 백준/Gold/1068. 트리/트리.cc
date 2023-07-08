#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

const int N_MAX = 50;
int N, tar, ans, root;
vector<int> tree[N_MAX];
int parents[N_MAX];
int visited[N_MAX] = {0, };

void input() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if(n == -1) {
            root = i;
            continue;
        }

        tree[n].push_back(i);
        parents[i] = n;
    }
    cin >> tar;
}

void bfs(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(tree[cur].size() == 0) ans++;
        for(int i = 0; i < tree[cur].size(); i++) {
            int next = tree[cur][i];

            if(!visited[next]) {
                q.push(next);
                visited[next] = 1;
            }
        }
    }
}

void delNode(int n) {
    for(int i = 0; i < tree[n].size(); i++) {
        if(tree[n][i] == tar) {
            tree[n].erase(tree[n].begin() + i);
        }
    }
}

void run() {
    if(tar == root) {
        cout << 0;
        return;
    }
    ans = 0;
    delNode(parents[tar]);
    bfs(root);
    cout << ans;
}

int main()
{
    fio;

    memset(parents, -1, sizeof(parents));
    input();
    run();

    return 0;
}