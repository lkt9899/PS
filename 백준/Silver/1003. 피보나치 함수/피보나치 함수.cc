#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

#define MAX_N 41

int T, N;
int arr[MAX_N];

void fibonacci(int n){
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
}

int getZero(int n) {
    if(n == 0) return 1;
    else if(n == 1) return 0;
    else return arr[n-1];
}

int getOne(int n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return arr[n];
}

int main()
{
    fio;

    cin >> T;
    for(int test = 0; test < T; test++) {
        cin >> N;
        fibonacci(N);

        cout << getZero(N) << " " << getOne(N) << "\n";
    }


    return 0;
}