#include <ios>

int main() {
    int N, K, W, V;
    scanf("%d %d", &N, &K);
    int dp[K + 1] = {0, };
    while(N--) {
        scanf("%d %d", &W, &V);
        for (int j = K; j >= W; j--)
            dp[j] = std::max(dp[j], dp[j - W] + V);
    }
    printf("%d", dp[K]);
    return 0;
}