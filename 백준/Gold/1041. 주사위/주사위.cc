#include <bits/stdc++.h>

using namespace std;

long long N;
long long arr[6], cnd[3];
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < 6; i++) cin >> arr[i];

    if(N == 1) {
        sort(arr, arr+6);
        for(int i = 0; i < 5; i++) ans += arr[i];
    }
    else {
        for(int i = 0; i < 3; i++) cnd[i] = min(arr[i], arr[5 - i]);
        sort(cnd, cnd+3);

        ans += cnd[0] * (5 * (N - 2) * (N - 2) + 4 * (N - 2));    // 한면만 -- 테두리 제외 가운데 총 5면, 옆면 맨 밑줄 N-2개씩 4면
        ans += (cnd[0] + cnd[1]) * (8 * (N - 2) + 4);           // 두면만 -- 윗면 4(N-2)개, 기둥 쪽 맨위 하나 제외 4개 4(N-1), 4(2N-3) = 8N - 12 = 8(N - 2) + 4
        ans += (cnd[0] + cnd[1] + cnd[2]) * 4;                  // 세면 보이는거 -- 4 기둥 꼭대기 하나씩 4개
    }

    cout << ans;

    return 0;
}