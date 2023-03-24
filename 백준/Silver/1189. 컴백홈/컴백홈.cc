#include <iostream>
#include <cstring>

#define _MAX 6

using namespace std;

int r, c, k, ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char map[_MAX][_MAX];

void init() {
    ans = 0;
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
}

void BackT(int depth, int x, int y) {
    map[y][x] = 'T';
    if(y == r-1 && x == 0) {
        if(depth == k-1) ans++;
        return;
    }
    else {
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < c && ny >= 0 && ny < r && map[ny][nx] != 'T') {
                BackT(depth+1, nx, ny);
                map[ny][nx] = '.';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    BackT(0, c-1, 0);

    cout << ans;
    return 0;
}