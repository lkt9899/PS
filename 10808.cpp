#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
constexpr int CTOI = 97;

using namespace std;


int main()
{
    fio;
    int arr[26] = {0, };
    string s; cin >> s;

    for(char c : s) {
        arr[(int)c - 97] += 1;
    }

    for(auto n : arr) cout << n << " ";
    
    return 0;
}