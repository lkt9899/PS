#include <iostream>

using namespace std;

int power(long long n, int p, int mod) {
    long long ans = 1;
    while (p > 0) {
        if (p % 2) {
            ans *= n;
            ans %= mod;
        }

        n *= n;
        n %= mod;

        p /= 2;
    }

    return ans;
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << power(A, B, C) << "\n";
}