#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    int arr[5];
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+5);
    cout << sum / 5 << "\n" << arr[2];
    return 0;
}