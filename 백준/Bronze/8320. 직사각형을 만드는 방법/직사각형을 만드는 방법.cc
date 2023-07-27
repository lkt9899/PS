#include <iostream>

using namespace std;

int main() {
    int N, ans = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j < N / i + 1; j++) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}