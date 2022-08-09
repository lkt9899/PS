#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    int a, b;
    cin >> a >> b;
    cout << (a >= b ? (a == b ? "==" : ">") : "<");

    return 0;
}