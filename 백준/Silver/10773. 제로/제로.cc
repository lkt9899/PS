#include <bits/stdc++.h>

using namespace std;

stack<int> s;
int N, num, ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        if(num) {
            s.push(num);
            ans += num;
        }
        else {
            ans -= s.top();
            s.pop();
        }
    }

    cout << ans;

    return 0;
}