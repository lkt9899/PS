#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp = 0, t = 9;
    while(t-1) {
        cin >> n;
        if(n != --t && n != ++tmp) break;
    }

    if(n == t) cout << "descending";
    else if(n == tmp) cout << "ascending";
    else cout << "mixed";

    return 0;
}