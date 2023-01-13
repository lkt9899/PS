#include <bits/stdc++.h>

using namespace std;

int X, ans;
int twos[7] = {1, 2, 4, 8, 16, 32, 64};

void calc(int x) {
    if(x == 0) return;

    int tmp = x;
    int i = 0;
    while(tmp != 1) {
        tmp = (tmp >> 1);
        i++;
    }
    ans++;
    calc(x - twos[i]);
}

int main() {
    cin >> X;
    ans = 0;
    calc(X);

    cout << ans;

    return 0;
}