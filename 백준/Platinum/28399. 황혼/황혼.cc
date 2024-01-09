#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 200001

using namespace std;

struct Edge {
    int e;
    long long c;
    int cnt, prev;
};

struct comp {
    bool operator()(Edge e1, Edge e2) { return e1.c > e2.c; }
};

const long long INF = 9223372036854775807ll;

int N, M, K;
long long dist[2][MAX_N];
vector<Edge> edges[MAX_N];
vector<int> infos[MAX_N];
priority_queue<Edge, vector<Edge>, comp> pq;

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        edges[s].push_back({e, c, -1, 0});
    }

    for (int i = 0; i < K; i++) {
        int cnt, start;
        cin >> cnt >> start;
        for (int j = 1; j < cnt; j++) {
            int next;
            cin >> next;
            infos[start].push_back(next);
        }
    }

    for (int i = 1; i <= N; i++) {
        dist[0][i] = INF;
        dist[1][i] = INF;
    }
}

void sol() {
    Edge start = {1, 0, -1, 0};
    if (!infos[1].empty()) {
        start.cnt = 0;
        start.prev = 1;
        dist[1][1] = 0;
    }

    pq.push(start);
    dist[0][1] = 0;
    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        int isInc = cur.prev ? 1 : 0;
        if (dist[isInc][cur.e] < cur.c) continue;

        for (Edge next : edges[cur.e]) {
            Edge newNext = next;
            long long nextDist = dist[isInc][cur.e] + next.c;
            int isInc2 = infos[next.e].empty() ? 0 : 1;

            // is min cost?
            if (nextDist < dist[isInc2][next.e]) {
                // is next node start of path?
                if (isInc2) {
                    newNext.cnt = 0;
                    newNext.prev = next.e;
                } else {
                    // is cur node in path?
                    if (isInc) {
                        // is next node linked at cur node?
                        if (infos[cur.prev][cur.cnt] == next.e) {
                            // is last node of path?
                            if (cur.cnt == infos[cur.prev].size() - 1) continue;
                            newNext.cnt = cur.cnt + 1;
                            newNext.prev = cur.prev;
                        }
                    }
                }

                dist[(newNext.prev ? 1 : 0)][next.e] = nextDist;
                newNext.c = nextDist;
                pq.push(newNext);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        long long d = min(dist[0][i], dist[1][i]);
        if (d == INF)
            cout << -1 << " ";
        else
            cout << d << " ";
    }
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