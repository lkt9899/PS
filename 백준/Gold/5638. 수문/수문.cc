#include <algorithm>
#include <iostream>
#include <vector>

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
#define INF 1000000001

using namespace std;

struct Info {
    int f, c;
};

bool compare(Info a, Info b) { return a.c < b.c; }

int N, T, A, H;
int minS;
long long minC;
vector<Info> dam;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int f, c;
        cin >> f >> c;
        dam.push_back({f, c});
    }
    sort(dam.begin(), dam.end(), compare);
}

void calc(int next, int sum, int cost, int visit) {
    if (sum != 0 && (A / (double)sum) <= H) {
        if (minC > cost) {
            minC = cost;
            minS = sum;
        }
        return;
    }

    for (int i = next; i < N; i++) {
        if (!(visit & (1 << i))) {
            if (sum + dam[i].f > minS) continue;
            calc(i + 1, sum + dam[i].f, cost + dam[i].c, visit | (1 << i));
        }
    }
}

void sol() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ": ";
        cin >> A >> H;

        minC = INF;
        minS = INF;
        calc(0, 0, 0, 0);

        if (minC == INF)
            cout << "IMPOSSIBLE\n";
        else
            cout << minC << "\n";
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