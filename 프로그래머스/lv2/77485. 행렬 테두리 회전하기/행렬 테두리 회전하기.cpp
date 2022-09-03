#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int dir[4] = {-1, -rows, 1, rows};
    int min, prev, pres, cnt = 0;
    int num = 1;
    
    // make original vector
    vector<vector<int>> og(rows, vector<int>(columns, 0));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++)
            og[i][j] = num++;
    }
    // rotation
    while(cnt < queries.size()) {
        // make rotation kernel
        min = rows * columns;
        int x1 = queries[cnt][0] - 1, y1 = queries[cnt][1] - 1;
        int x2 = queries[cnt][2] - 1, y2 = queries[cnt][3] - 1;
        int _r = x2 - x1 + 1    , _c = y2 - y1 + 1;

        int kx = x1, ky = y1;
        prev = og[kx+1][ky];
        pres = og[kx][ky];
        for(int dy = 1; dy < _c; dy++) {
            ky++;
            prev = pres;
            pres = og[kx][ky];
            og[kx][ky] = prev;
            min = (og[kx][ky] < min) ? og[kx][ky] : min;
        }
        for(int dx = 1; dx < _r; dx++) {
            kx++;
            prev = pres;
            pres = og[kx][ky];
            og[kx][ky] = prev;
            min = (og[kx][ky] < min) ? og[kx][ky] : min;
        }
        for(int dy = 1; dy < _c; dy++){
            ky--;
            prev = pres;
            pres = og[kx][ky];
            og[kx][ky] = prev;
            min = (og[kx][ky] < min) ? og[kx][ky] : min;
        }
        for(int dx = 1; dx < _r; dx++){
            kx--;
            prev = pres;
            pres = og[kx][ky];
            og[kx][ky] = prev;
            min = (og[kx][ky] < min) ? og[kx][ky] : min;
        }
        answer.push_back(min);
        cnt++;
    }
    return answer;
}