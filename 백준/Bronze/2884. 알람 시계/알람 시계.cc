#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    int h, m;
    cin >> h >> m;
    m += 15;
    if (m >= 60)
    {
        m -= 60;
    }
    else
    {
        h--;
        if (h < 0)
            h = 23;
    }
    cout << h << " " << m;
    return 0;
}