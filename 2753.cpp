#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    int year; cin >> year;
    
    if(year % 4 == 0) {
        if(year % 400 == 0) cout << 1;
        else if(year % 100 == 0) cout << 0;
        else cout << 1;
    }
    else cout << 0;
    
    return 0;
}