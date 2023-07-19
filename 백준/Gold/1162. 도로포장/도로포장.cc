#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>

using namespace std;

const int N_MAX = 10001, M_MAX = 50001, K_MAX = 21;
int N, M, K;
long long int costs[N_MAX][K_MAX];
vector<pii> road[N_MAX];
priority_queue<pair<long long, pii>> pq;

void init()
{
    memset(costs, -1, sizeof(costs) * (N+1) / N_MAX);
}

long long int dijkstra(int start) {
    init();
    int now, next;
    long long int cost, nCost, min_cost = -1;

    costs[start][0] = 0;
    pq.push(make_pair(-0, make_pair(start, 0)));

    while (!pq.empty()) {
        cost = -pq.top().first;
        now = pq.top().second.first;
        int cnt = pq.top().second.second;
        pq.pop();

        if (cost > costs[now][cnt])
            continue;

        for (int i = 0; i < road[now].size(); i++) {
            next = road[now][i].first;
            nCost = cost + road[now][i].second;

            if (cnt < K) {
                if (costs[next][cnt + 1] == -1) {
                    costs[next][cnt + 1] = cost;
                    pq.push(make_pair(-cost, make_pair(next, cnt + 1)));
                }

                if (costs[next][cnt + 1] > cost) {
                    costs[next][cnt + 1] = cost;
                    pq.push(make_pair(-cost, make_pair(next, cnt + 1)));
                }
            }

            if (costs[next][cnt] > nCost || costs[next][cnt] == -1) {
                costs[next][cnt] = nCost;
                pq.push(make_pair(-nCost, make_pair(next, cnt)));
            }
        }
    }

    min_cost = costs[N][0];
    for (int i = 1; i <= K; i++) {
        if (costs[N][i] == -1)
            continue;
        min_cost = min_cost > costs[N][i] ? costs[N][i] : min_cost;
    }

    return min_cost;
}

void sol()
{
    cout << dijkstra(1) << "\n";
}

void input()
{
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        road[s].push_back(make_pair(e, t));
        road[e].push_back(make_pair(s, t));
    }
}

void run()
{
    input();
    sol();
}

int main()
{
    fio;
    run();

    return 0;
}