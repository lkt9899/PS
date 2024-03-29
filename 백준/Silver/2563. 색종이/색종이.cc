#include <cstring>
#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int MAX = 101;
int N, ans;
int board[MAX][MAX];

void init() {
    ans = 0;
    memset(board, 0, sizeof(board));
}

void cover(int x, int y) {
    for (int i = y; i < y + 10; i++) {
        for (int j = x; j < x + 10; j++) {
            board[i][j] = 1;
        }
    }
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        cover(x, y);
    }
}

void sol() {
    int ni, nj;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (board[i][j] == 1) {
                ans++;
            }
        }
    }

    cout << ans;
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