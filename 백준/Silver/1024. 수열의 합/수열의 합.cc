#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, L;

int getX(int t, int l) {
    return (N - t) / l;
}

int main()
{
    fio;

    cin >> N >> L;

    int x = -1;
    while(L <= 100) {
        int t = L * (L-1) / 2;
        if((N - t) % L == 0 && t <= N) {
            x = getX(t, L);
            break;
        }
        else L++;
    }

    if(x == -1) cout << -1;
    else {
        for(int i = 0; i < L; i++) {
            cout << x+i << " ";
        }
    }

    return 0;
}