#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct Axis {
    int i, j;
};

const int N_MAX = 20;
int N, visited[N_MAX];
double ans;
Axis axis[N_MAX];

Axis& operator -=(Axis &a, Axis b) {
    a.i -= b.i;
    a.j -= b.j;
    return a;
}

Axis& operator +=(Axis &a, Axis b) {
    a.i += b.i;
    a.j += b.j;
    return a;
}

double getVectorSum() {
    Axis tmp = {0, 0};
    for (int i = 0; i < N; i++) {
        if(visited[i]) {
            tmp -= axis[i];
        } else {
            tmp += axis[i];
        }
    }

    return sqrt(pow(tmp.i, 2) + pow(tmp.j, 2));
}

void dfs(int n, int cnt) {
    if(cnt == N / 2) {
        ans = min(getVectorSum(), ans);
        return;
    }

    for (int i = n; i < N; i++) {
        visited[i] = 1;
        dfs(i + 1, cnt + 1);
        visited[i] = 0;
    }
}

void Sol() {
    dfs(0, 0);
    printf("%.7lf\n", ans);
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        axis[i] = {x, y};
    }
}

void init() {
    memset(visited, 0, sizeof(visited));
    ans = 1e9 + 7;
}

void run() {
    init();
    input();
    Sol();
}

int main(int argc, char** argv)
{
    int T, test_case;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        run();
    }
    return 0;
}