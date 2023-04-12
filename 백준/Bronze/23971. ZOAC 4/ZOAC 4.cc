#include <bits/stdc++.h>

using namespace std;

double h, w, n, m;

void input() {
    cin >> h >> w >> n >> m;
    n++;
    m++;
}

int run() {
    return ceil(h/n) * ceil(w/m);
}

int main() {
    ios_base::sync_with_stdio(0);

    input();
    cout << run();

    return 0;
}