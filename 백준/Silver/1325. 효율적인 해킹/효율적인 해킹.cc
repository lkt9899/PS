#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define i2(a, b) cin >> a >> b

#define MAX_N 10001

using namespace std;

int N, M;
vector<int> edges[MAX_N];
int hackingCnt[MAX_N];
bool visit[MAX_N];

void init() { memset(hackingCnt, 0, sizeof(hackingCnt)); }

void input() {
    i2(N, M);
    for (int i = 0; i < M; i++) {
        int s, e;
        i2(s, e);
        edges[s].push_back(e);
    }
}

void dfs(int start) {
    hackingCnt[start]++;
    visit[start] = true;
    for (int next : edges[start]) {
        if (!visit[next]) {
            dfs(next);
        }
    }
}

void sol() {
    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));
        if (!visit[i]) dfs(i);
    }

    vector<int> v;
    int maxHackingCnt = 0;
    for (int i = 1; i <= N; i++) {
        if (maxHackingCnt == hackingCnt[i])
            v.push_back(i);
        else if (maxHackingCnt < hackingCnt[i]) {
            maxHackingCnt = hackingCnt[i];
            v.clear();
            v.push_back(i);
        }
    }
    
    sort(v.begin(), v.end());
    for (int idx : v) cout << idx << " ";
}

void run() {
    input();
    sol();
}

int main() {
    fio;
    run();
    return 0;
}