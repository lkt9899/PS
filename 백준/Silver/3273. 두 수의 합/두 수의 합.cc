#include <bits/stdc++.h>

#define MAX 2000001

using namespace std;

int N, x;
int arr[1000001];
int cnt[MAX] = {0, };

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> x;
    for(int i = 0; i < N; i++) {
        if(x - arr[i] > 0 && cnt[x - arr[i]]) ans++;
        cnt[arr[i]]++;
    }
    cout << ans;

    return 0;
}