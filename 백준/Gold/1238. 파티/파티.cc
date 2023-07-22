#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define pii pair<int, int>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int N_MAX = 1001;
const int INF = 1e9 + 7;
int N, X, M;
vector<pii> road[2][N_MAX];		// 방향, 도착 점, 비용
int costs[2][N_MAX];	// 방향, 도착 점

void init() {
	memset(costs, INF, sizeof(costs));
}

void dijkstra(int mode) {
	int now, next, cost, nCost;

	costs[mode][X] = 0;
	priority_queue<pii> pq;
	pq.push(make_pair(-0, X));

	while (!pq.empty()) {
		cost = -pq.top().first;
		now = pq.top().second;
		pq.pop();

		if (cost > costs[mode][now]) continue;

		for (int i = 0; i < road[mode][now].size(); i++) {
			next = road[mode][now][i].first;
			nCost = cost + road[mode][now][i].second;

			if (nCost < costs[mode][next]) {
				costs[mode][next] = nCost;
				pq.push(make_pair(-nCost, next));
			}
		}
	}
}

void sol() {
	dijkstra(1);
	dijkstra(0);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, costs[0][i] + costs[1][i]);
	}

	cout << ans << "\n";
}

void input() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		road[0][s].push_back(make_pair(e, t));
		road[1][e].push_back(make_pair(s, t));
	}
}

void run() {
	init();
	input();
	sol();
}

int main()
{
    fio;
	run();
}