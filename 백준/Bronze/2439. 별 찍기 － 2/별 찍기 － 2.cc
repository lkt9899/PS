#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < N - i; j++)  cout << " ";
        for(int k = 0; k < i; k++)  cout << "*";
        cout << "\n";
    }

    return 0;
}