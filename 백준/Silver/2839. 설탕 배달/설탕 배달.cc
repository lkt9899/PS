#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, ans;

void input() { cin >> N; }

void sol() {
    ans = 0;
    while (N >= 0) {
        if (N % 5 == 0) {
            ans += (N / 5);
            cout << ans << "\n";
            return;
        }
        N -= 3;
        ans++;
    }
    cout << -1 << "\n";
}

void run() {
    input();
    sol();
}

int main() {
    fio;
    run();
    return 0;
}