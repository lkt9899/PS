#include <cstring>
#include <iostream>

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 1001

using namespace std;

int T, N, M, a, b, p, q, _max, _min;
int win[MAX_N], lose[MAX_N];

void init() {
    _max = 0;
    _min = 1001;
    memset(win, 0, sizeof(win));
    memset(lose, 0, sizeof(lose));
}

int getScore(int S, int A) {
    if (S == 0 && A == 0) return 0;
    double res, num, den;
    num = S * S;
    den = S * S + A * A;
    res = num / den;
    return res * 1000.0;
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> p >> q;
        win[a] += p;
        lose[a] += q;
        win[b] += q;
        lose[b] += p;
    }
}

void sol() {
    init();
    input();
    for (int i = 1; i <= N; i++) {
        int score = getScore(win[i], lose[i]);
        _max = max(_max, score);
        _min = min(_min, score);
    }

    cout << _max << "\n" << _min << "\n";
}

int main() {
    fio;
    cin >> T;
    for (int t = 0; t < T; t++) {
        sol();
    }
    return 0;
}