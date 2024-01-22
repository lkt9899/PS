#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define i2(a, b) cin >> a >> b
#define fi0(e) for (int i = 0; i < e; i++)

#define MAX_K 100001

using namespace std;

int N, K;
int dp[MAX_K];

void sol() {
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

int main() {
    fio;
    sol();
    return 0;
}