#include <bits/stdc++.h>

using namespace std;

int N, K;
queue<int> q;

void summation(int n) {
    int cur = 1;
    while (n) {
        if (n % 2) {
            q.push(cur);
        }
        n /= 2;
        cur *= 2;
    }
}

int main() {
    int ans = 0;
    scanf("%d %d", &N, &K);

    if(N > K) {
        summation(N);
        if(q.size() > K) {
            int tmp = 0;
            while(q.size() > K) {
                tmp += q.front();
                q.pop();
            }
            ans = q.front() - tmp;
        }
    }
    printf("%d", ans);

    return 0;
}