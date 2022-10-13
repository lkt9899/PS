#include <bits/stdc++.h>

using namespace std;

int n, i, num = 1;
string ans;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> i;
        while(num <= i) {
            s.push(num++);
            ans += "+\n";
        }
        if(s.top() != i) {
            cout << "NO\n";
            return 0;
        }
        s.pop();
        ans += "-\n";
    }

    cout << ans;
    return 0;
}