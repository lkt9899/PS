#include <cstring>
#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define i1(a) cin >> a
#define i2(a, b) cin >> a >> b
#define i3(a, b, c) cin >> a >> b >> c

#define fi0(e) for (int i = 0; i < e; i++)
#define fi1(e) for (int i = 1; i <= e; i++)
#define fj0(e) for (int j = 0; j < e; j++)
#define fj1(e) for (int j = 1; j < e; j++)

#define M_MAX 701

using namespace std;

int M, N;
int cmd[M_MAX][M_MAX];

void print() {
    fi0(M) {
        cout << cmd[i][0] + 1 << " ";
        fj1(M) { cout << cmd[0][j] + 1 << " "; }
        cout << "\n";
    }
}

void input() {
    i2(M, N);
    fi0(N) {
        int row = M - 1;
        int col = 0;
        fj0(3) {
            int cnt;
            i1(cnt);
            while (cnt--) {
                if (row != 0)
                    cmd[row--][0] += j;
                else
                    cmd[0][col++] += j;
            }
        }
    }
}

void sol() { print(); }

void run() {
    input();
    sol();
}

int main() {
    fio;
    run();
    return 0;
}