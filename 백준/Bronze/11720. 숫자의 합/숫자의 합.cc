#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    int t, ans = 0;
    string s;
    cin >> t >> s;
    for(int i = 0; i < t; i++) {
        ans += int(s[i] - 48);
    }
    cout << ans;
    
    return 0;
}