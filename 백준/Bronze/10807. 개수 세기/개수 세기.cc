#include <bits/stdc++.h>

#define MAX 201

using namespace std;

int N, V, tmp;
int arr[MAX] = {0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        arr[tmp + 100]++;
    }
    cin >> V;
    cout << arr[V+100];
    
    return 0;
}