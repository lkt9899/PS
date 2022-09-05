#include <bits/stdc++.h>

#define N_MAX 20

using namespace std;

int N, mTime[N_MAX], ySum = 0, mSum = 0;

void check() {
    for(int i = 0; i < N; i++) {
        ySum += (1 + mTime[i] / 30) * 10;
        mSum += (1 + mTime[i] / 60) * 15;
    }
    if(ySum < mSum) cout << "Y " << ySum;
    else if(mSum < ySum)   cout << "M " << mSum;
    else    cout << "Y M " << ySum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> mTime[i];
    }

    check();

    return 0;
}