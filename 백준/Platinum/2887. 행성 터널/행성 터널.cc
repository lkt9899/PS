#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
#define MAX_N 100001

using namespace std;

int N;
int parents[MAX_N];
vector<pii> xEdges, yEdges, zEdges;
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;

void init() {
    for (int i = 0; i < N; i++) {
        parents[i] = i;
    }
}

void input() {
    cin >> N;
    init();

    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        xEdges.push_back({x, i});
        yEdges.push_back({y, i});
        zEdges.push_back({z, i});
    }

    sort(xEdges.begin(), xEdges.end());
    sort(yEdges.begin(), yEdges.end());
    sort(zEdges.begin(), zEdges.end());
}

int find(int a) {
    if (parents[a] == a) return a;
    return parents[a] = find(parents[a]);
}

void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) return;

    parents[rootB] = rootA;
}

void getEdges() {
    for (int i = 0; i < N - 1; i++) {
        pq.push({xEdges[i + 1].first - xEdges[i].first, {xEdges[i].second, xEdges[i + 1].second}});
        pq.push({yEdges[i + 1].first - yEdges[i].first, {yEdges[i].second, yEdges[i + 1].second}});
        pq.push({zEdges[i + 1].first - zEdges[i].first, {zEdges[i].second, zEdges[i + 1].second}});
    }
}

void sol() {
    getEdges();

    int cost = 0;
    for (int i = 1; i < N; i++) {
        while (!pq.empty()) {
            pair<int, pii> e = pq.top();
            pq.pop();
            if (find(e.second.first) != find(e.second.second)) {
                unite(e.second.first, e.second.second);
                cost += e.first;
                break;
            }
        }
    }

    cout << cost << "\n";
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