#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    int A, B, C; cin >> A >> B >> C;
    int res = A * B * C;
    int arr[10] = { 0, };
    while(res) {
        arr[res % 10] += 1;
        res /= 10;
    }

    for(auto n : arr) cout << n << "\n";
    
    return 0;
}