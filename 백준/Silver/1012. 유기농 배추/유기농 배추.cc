#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

#define MAX_N 51
#define MAX_M 51

int T, N, M, K, ans;
int graph[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];
int i_dir[4] = {0, 1, 0, -1};
int j_dir[4] = {1, 0, -1, 0};

void init() {
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    ans = 0;
}

void makeGraph() {
    int x, y;
    for(int i = 0; i < K; i++) {
        cin >> x >> y;
        graph[y][x] = 1;
    }
}

bool check(int i, int j) {
    return (i < 0 || i >= N || j < 0 || j >= M || graph[i][j] == 0 || visited[i][j] == 1);
}

void dfs(int ii, int jj) {
    int x, y;
    visited[ii][jj] = 1;

    for(int i = 0; i < 4; i++) {
        x = jj + j_dir[i];
        y = ii + i_dir[i];
        if(check(y, x)) continue;
        dfs(y, x);  
    }
}

void run() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == 0 || visited[i][j] == 1) continue;
            dfs(i, j);
            ans++;
        }
    }
}

int main()
{
    fio;
    
    cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> M >> N >> K;

        init();
        makeGraph();
        run();
        
        cout << ans << "\n";
    }


    return 0;
}