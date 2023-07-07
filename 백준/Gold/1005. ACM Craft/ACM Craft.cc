#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int N_MAX = 1001;
const int K_MAX = 100001;

int N, K, W;
int dist[K_MAX];
int dp[N_MAX];
vector<int> parents[N_MAX];

void init() {
    for(int i = 0; i < N_MAX; i++) parents[i].clear();
    memset(dp, -1, sizeof(dp));
}

int getDist(int n) {
    if(dp[n] != -1) return dp[n];
    else {
        if(parents[n].size() == 0) {
            dp[n] = dist[n];
            return dp[n];
        } else {
            queue<int> q;
            for(int i = 0; i < parents[n].size(); i++) {
                q.push(parents[n][i]);
            }

            int cmax = 0;
            while(!q.empty()) {
                int cur = q.front();
                q.pop();

                if(dp[cur] == -1) {
                    int d = getDist(cur);
                    cmax = cmax < d ? d : cmax;
                }
                else {
                    cmax = cmax < dp[cur] ? dp[cur] : cmax;
                }
            }
            dp[n] = cmax + dist[n];
            return dp[n];
        }
    }
}

void input() {
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> dist[i];
    for(int i = 1; i <= K; i++) {
        int s, e;
        cin >> s >> e;
        parents[e].push_back(s);
    }
    cin >> W;
}

int main(int argc, char** argv)
{
    int T, test_case;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        init();
        input();
        getDist(W);
        cout << dp[W] << "\n";
    }
    return 0;
}