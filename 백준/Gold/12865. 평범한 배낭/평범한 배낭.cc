#include <iostream> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, K, W, V;
    int dp[100001] = {0, };
    cin >> N >> K;
    while(N--) {
        cin >> W >> V;
        for (int j = K; j >= W; j--)
            dp[j] = max(dp[j], dp[j - W] + V);
    }
    cout << dp[K];
    return 0;
}