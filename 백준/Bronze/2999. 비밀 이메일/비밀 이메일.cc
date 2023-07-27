#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
    fio;
    
    string s;
    cin >> s;
    
    int len = s.length();
    int r = 1, c = len, i = 0;
    while (r <= c) {
        i++;
        if (len % i != 0) continue;
        if (len / i >= i) {
            r = i;
            c = len / i;
        } else
            break;
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; i + j < len; j += r) {
            cout << s[i + j];
        }
    }
    
    return 0;
}