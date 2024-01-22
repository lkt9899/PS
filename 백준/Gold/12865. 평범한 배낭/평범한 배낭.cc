#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define i2(a, b) cin >> a >> b
#define fi0(e) for (int i = 0; i < e; i++)

using namespace std;

int main() {
    fio;
    int N, K, W, V;
    int dp[100001] = {0, };
    i2(N, K);
    fi0(N) {
        i2(W, V);
        for (int j = K; j >= W; j--) {
            dp[j] = dp[j] > dp[j - W] + V ? dp[j] : dp[j - W] + V;
        }
    }
    cout << dp[K];
    return 0;
}