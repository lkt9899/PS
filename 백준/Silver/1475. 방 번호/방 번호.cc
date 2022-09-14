#include <bits/stdc++.h>

using namespace std;

int num[10] = {0, };
int _max = 0;
int idx;
string s;

int main() {
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        idx = (int)s[i] - 48;
        num[idx]++;
    }

    num[6] = (num[6] + num[9] + 1) / 2;
    for(int i = 0; i < 9; i++) {
        _max = _max > num[i] ? _max : num[i];
    }

    cout << _max << "\n";
    return 0;
}