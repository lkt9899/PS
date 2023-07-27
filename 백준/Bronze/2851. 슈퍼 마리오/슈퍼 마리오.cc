#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int ans, arr[10];

void init() { ans = 0; }

void input() {
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
}

void sol() {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += arr[i];
        if (sum >= 100) {
            ans = (100 - sum + arr[i]) < (sum - 100) ? sum - arr[i] : sum;
            break;
        } else
            ans = sum;
    }

    cout << ans;
}

void run() {
    init();
    input();
    sol();
}

int main() {
    fio;
    run();
    return 0;
}