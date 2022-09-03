#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
constexpr int NUM_MAX = 100;

int main()
{
    fio;
    int num, small=NUM_MAX, sum=0;
    for(int i = 0; i < 7; i++) {
        cin >> num;
        if(num % 2 == 0) continue;
        small = small < num ? small : num;
        sum += num;
    }
    if(sum == 0) cout << -1;
    else cout << sum << "\n" << small;
    return 0;
}