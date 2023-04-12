#include <bits/stdc++.h>

using namespace std;

double h, w, n, m;

int main() {
    cin >> h >> w >> n >> m;
    cout << (long long)ceil(h/++n) * (long long)ceil(w/++m);
    return 0;
}