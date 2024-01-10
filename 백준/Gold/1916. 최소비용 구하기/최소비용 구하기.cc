#include <iostream>
#include <queue>
#include <vector>

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 1001
#define INF 123456789

using namespace std;

struct Edge {
    int e, c;
};

struct comp {
    bool operator()(Edge e1, Edge e2) { return e1.c < e2.c; }
};

int N, M, S, E;
int dist[MAX_N];
vector<Edge> edges[MAX_N];
priority_queue<Edge, vector<Edge>, comp> pq;

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        edges[s].push_back({e, c});
    }

    cin >> S >> E;
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
}

void sol() {
    pq.push({S, 0});
    dist[S] = 0;

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        if (dist[cur.e] < cur.c) continue;

        for (Edge next : edges[cur.e]) {
            int nextDist = cur.c + next.c;

            if (nextDist < dist[next.e]) {
                dist[next.e] = nextDist;
                pq.push({next.e, nextDist});
            }
        }
    }

    cout << dist[E] << "\n";
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