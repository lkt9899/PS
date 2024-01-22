#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define i1(a) cin >> a
#define i2(a, b) cin >> a >> b
#define i3(a, b, c) cin >> a >> b >> c

#define fi0(e) for (int i = 0; i < e; i++)
#define fi1(e) for (int i = 1; i <= e; i++)
#define fj0(e) for (int j = 0; j < e; j++)
#define fj1(e) for (int j = 1; j <= e; j++)

#define MAX_K 100001

using namespace std;

int N, K;
int dp[MAX_K];

void input() {
    i2(N, K);
    fi0(N) {
        int w, v;
        i2(w, v);
        for (int j = K; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[K];
}

void sol() {}

void run() {
    input();
    sol();
}

int main() {
    fio;
    run();
    return 0;
}