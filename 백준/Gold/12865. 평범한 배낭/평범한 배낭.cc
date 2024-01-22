#include <ios>

int main() {
    int N, K, W, V;
    int dp[K + scanf("%d %d", &N, &K)] = { };
    while(N--) {
        scanf("%d %d", &W, &V);
        for (int j = K; j >= W; j--)
            dp[j] = std::max(dp[j], dp[j - W] + V);
    }
    printf("%d", dp[K]);
    return 0;
}