#include <bits/stdc++.h>

using namespace std;

double h, w, n, m;

int main() {
    cin >> h >> w >> n >> m;
    cout << (int)(ceil(h/++n) * ceil(w/++m));
    return 0;
}