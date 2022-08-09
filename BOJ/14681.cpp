#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    int x, y; cin >> x >> y;
    if(x < 0) {
        cout << (y < 0 ? 3 : 2);
    }
    else {
        cout << (y < 0 ? 4 : 1);
    }
    return 0;
}