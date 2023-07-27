#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int arr[42];

void run() {
    fill(&arr[0], &arr[42], 0);

    int num, r, ans = 0;

    for (int i = 0; i < 10; i++) {
        cin >> num;
        r = num % 42;
        if (arr[r] != 0)
            continue;
        else {
            arr[r] = 1;
            ans++;
        }
    }
    cout << ans;
}

int main() {
    fio;
    run();
    return 0;
}