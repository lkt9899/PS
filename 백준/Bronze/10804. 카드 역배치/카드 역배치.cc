#include <bits/stdc++.h>

using namespace std;

int a, b, cnt;
int arr[21];

void rArr(int start, int end) {
    int tmp;
    for(int i = 0; i < cnt / 2; i++) {
        tmp = arr[start + i];
        arr[start + i] = arr[end - i];
        arr[end - i] = tmp;    
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 21; i++) arr[i] = i;

    for(int i = 0; i < 10; i++) {
        cin >> a >> b;
        if(a == b) continue;
        cnt = b - a + 1;
        rArr(a, b);
    }

    for(int i = 1; i < 21; i++) cout << arr[i] << " ";

    return 0;
}