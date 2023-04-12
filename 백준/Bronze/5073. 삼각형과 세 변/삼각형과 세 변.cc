#include <bits/stdc++.h>

using namespace std;

string ans[4] = {"Equilateral", "Scalene", "Isosceles", "Invalid"};
int a[3] = {0, };

int run() {
    if(a[2] >= a[0] + a[1]) return 3;
    else if(a[0] == a[2]) return 0;
    else if(a[0] != a[1] && a[1] != a[2]) return 1;
    else if(a[0] == a[1] || a[1] == a[2]) return 2;
}

int main() {
    while(1) {
        cin >> a[0] >> a[1] >> a[2];
        if(a[0] == 0) break;
        sort(a, a+3);
        cout << ans[run()] << "\n";
    }

    return 0;
}