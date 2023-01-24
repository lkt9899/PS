#include <bits/stdc++.h>

using namespace std;

int N, R, C, ans = 0;

void find(int n, int tr, int tc) {
    if(n == 0) return;
    int mLen = pow(2, n-1);

    if(R == tr && C == tc) {
        ans += (mLen * mLen * 3);
        return;
    }
    else if(R < tr && C < tc) {
        find(n-1, tr - mLen/2, tc - mLen/2);
    }
    else if(R < tr && C >= tc) {
        ans += mLen * mLen;
        find(n-1, tr - mLen/2, tc + mLen/2);
    }
    else if(R >= tr && C < tc) {
        ans += (mLen * mLen * 2);
        find(n-1, tr + mLen/2, tc - mLen/2);
    }
    else {
        ans += (mLen * mLen * 3);
        find(n-1, tr + mLen/2, tc + mLen/2);
    }
}

int main() {
    cin >> N >> R >> C;

    find(N, pow(2, N-1), pow(2, N-1));
    cout << ans;

    return 0;
}