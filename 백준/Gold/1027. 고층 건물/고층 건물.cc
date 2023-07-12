#include <bits/stdc++.h>

using namespace std;

const int MAX = 51;
int N, ans;
double a, b;
double arr[MAX];

void input() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
}

void getFunc(int x1, int x2) {
    a = (arr[x1] - arr[x2]) / (x1 - x2);
    b = arr[x1] - a * x1;
}

bool check(int x1, int x2) {
    int big, small;
    if(x1 > x2) {
        big = x1, small = x2;
    } else {
        big = x2, small = x1;
    }

    for(int i = small + 1; i < big; i++) {
        double y = (double)(a * i) + b;
        if(y <= arr[i]) return 0;
    }

    return 1;
}

void run() {
    input();

    int max = 0;
    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;
            getFunc(i, j);
            if(check(i, j)) cnt++;
        }
        max = max < cnt ? cnt : max;
    }
    cout << max;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    run();

    return 0;
}