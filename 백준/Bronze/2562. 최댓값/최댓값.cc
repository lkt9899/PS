#include <bits/stdc++.h>

using namespace std;

int arr[9], _max, idx;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    _max = 0;
    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
        if(_max < arr[i]) {
            _max = arr[i];
            idx = i + 1;
        }
    }

    cout << _max << "\n" << idx;
    
    return 0;
}