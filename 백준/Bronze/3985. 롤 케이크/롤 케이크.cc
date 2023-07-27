#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int L, N, eL, eI, aL, aI;
int arr[1001];
vector<pair<int, int>> v;

void init() {
    eL = eI = aL = aI = -1;
    memset(arr, 0, sizeof(arr));
}

void input() {
    cin >> L >> N;
    for (int i = 1; i <= N; i++) {
        int s, e;
        cin >> s >> e;
        if (e - s + 1 > eL) {
            eL = e - s + 1;
            eI = i;
        }
        v.push_back({s, e});
    }
}

void sol() {
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = v[i].first; j <= v[i].second; j++) {
            if (arr[j] == 0) {
                arr[j] = 1;
                cnt++;
            }
        }
        if (aL < cnt) {
            aL = cnt;
            aI = i + 1;
        }
    }
    cout << eI << "\n" << aI;
}

void run() {
    init();
    input();
    sol();
}

int main() {
    fio;
    run();
    return 0;
}