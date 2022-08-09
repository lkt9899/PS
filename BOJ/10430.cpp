#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    int a, b, c; cin >> a >> b >> c;
    cout << (a+b)%c << "\n" << (a+b)%c << "\n" << (a*b)%c << "\n" << (a*b)%c;
    return 0;
}