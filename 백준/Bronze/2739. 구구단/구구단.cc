#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(0), cin.tie(0);

using namespace std;

int main()
{
    fio;
    int n;
    cin >> n;
    for (int i = 1; i < 10; i++)
        printf("%d * %d = %d\n", n, i, n * i);
    return 0;
}