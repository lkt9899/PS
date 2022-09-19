#include <bits/stdc++.h>

using namespace std;

int N, K, S, G;
int arr[2][7] = {0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> S >> G;
        arr[S][G]++;
    }
    int ans = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j < 7; j++) {
            while(arr[i][j] > 0) {
                ans++;
                arr[i][j] -= K;
            } 
        }
    }
    cout << ans;
    return 0;
}