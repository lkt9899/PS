#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

constexpr int MAX_INPUT = 9;

using namespace std;

int arr[MAX_INPUT];

void calc() {
    int total = 0;
    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    
    for(int i = 0; i < 8; i++) {
        for(int j = i+1; j < 9; j++) {
            if(total - arr[i] - arr[j] == 100) {
                arr[i] = 0; arr[j] = 0;
                sort(arr, arr+9);
                break;
            }
        }
        if(arr[i] == 0) break;
    }

    for(int i = 2; i < 9; i++) {
        cout << arr[i] << "\n";
    }
}

int main()
{
    fio;
    calc();

    return 0;
}