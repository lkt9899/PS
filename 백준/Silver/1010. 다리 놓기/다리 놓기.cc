#include <bits/stdc++.h>

using namespace std;

int N, M, T;
long long result;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for(int t = 0; t < T; t++) {
        result = 1;
        cin >> N >> M;
        for(int i = 0; i < N; i++) {
            result *= (M - i);
            result /= (1 + i);
        }
        cout << result << "\n";
    }

    return 0;
}