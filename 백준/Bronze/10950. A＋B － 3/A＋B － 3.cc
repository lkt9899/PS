#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    int a, b, T; cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> a >> b;
        cout << a+b << "\n";
    }
    return 0;
}