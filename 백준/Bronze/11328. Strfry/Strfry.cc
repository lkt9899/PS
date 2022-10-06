#include <bits/stdc++.h>

using namespace std;

int N;
string s1, s2;

void check(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 == s2) cout << "Possible\n";
    else cout << "Impossible\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s1 >> s2;
        check(s1, s2);
    }

    return 0;
}