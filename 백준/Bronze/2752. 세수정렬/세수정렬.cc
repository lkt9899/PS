#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;
    int arr[3];
    for(int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+3);
    printf("%d %d %d", arr[0], arr[1], arr[2]);
    
    return 0;
}