#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    for(int t = 0; t < 3; t++) {
        int a;
        int b = 0, s = 0;
        for(int i = 0; i < 4; i++) {
            cin >> a;

            if(a == 0) b++;
            else s++;
        }
        if(b == 0) cout << "E\n";
        else cout << char(64 + b) << "\n";
    }

    return 0;
}