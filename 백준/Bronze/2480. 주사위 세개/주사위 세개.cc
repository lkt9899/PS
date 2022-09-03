#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    int arr[3];
    for(int i = 0; i < 3; i++) cin >> arr[i];
    sort(arr, arr+3);

    if(arr[0] == arr[2]) cout << 10000 + arr[0] * 1000;
    else if(arr[0] == arr[1] || arr[1] == arr[2]) cout << 1000 + arr[1] * 100;
    else cout << arr[2] * 100;

    return 0;
}