#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

int main()
{
    fio;
    int a, b, n1, n2, n3, res;
    cin >> a >> b;
    n3 = (b / 100) * a;
    n1 = (b % 10) * a;
    n2 = ((b / 10) % 10) * a;
    res = n1 + n2 * 10 + n3 * 100;
    printf("%d\n%d\n%d\n%d\n", n1, n2, n3, res);
    return 0;
}