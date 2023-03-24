#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0);
#define MAX_N 1001

using namespace std;

int N;
int arr[MAX_N][3] = {0, };
int dp[MAX_N][3] = {0, };

int main()
{
    fio;

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        if(i == 0) {
            dp[i][0] = arr[i][0];
            dp[i][1] = arr[i][1];
            dp[i][2] = arr[i][2];
        }
        dp[i][0] = arr[i][0] + (dp[i-1][1] < dp[i-1][2] ? dp[i-1][1] : dp[i-1][2]); 
        dp[i][1] = arr[i][1] + (dp[i-1][0] < dp[i-1][2] ? dp[i-1][0] : dp[i-1][2]); 
        dp[i][2] = arr[i][2] + (dp[i-1][1] < dp[i-1][0] ? dp[i-1][1] : dp[i-1][0]);
    }

    sort(dp[N-1], dp[N-1]+3);

    cout << dp[N-1][0];

    return 0;
}