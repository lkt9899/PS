#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int dir[2] = { 0, 1 };

void gravity(vector<string>& board) {
    int x_size = board[0].size();
    int y_size = board.size();
    
    for (int i = 0; i < x_size; i++) {
        int zero = 0;
        for (int j = y_size - 1, jj = 0; jj < y_size; jj++, j--) {
            if (board[j][i] == '0')
                zero++;
            else if(board[j][i] != 0 && zero != 0){
                board[j + zero][i] = board[j][i];
                board[j][i] = '0';
            }
        }
    }
}

int check(vector<string>& board) {
    int cnt = 0;
    int x_size = board[0].size();
    int y_size = board.size();
    list<int> ij;

    for (int i = 0; i < y_size - 1; i++) {
        for (int j = 0; j < x_size - 1; j++) {
            char s = board[i][j];
            if (s != '0' && s == board[i + 1][j] && s == board[i][j + 1] && s == board[i + 1][j + 1]) {
                ij.push_back(i);
                ij.push_back(j);
            }
        }
    }

    while(!ij.empty()) {
        int i = ij.front();
        ij.pop_front();
        int j = ij.front();
        ij.pop_front();

        for (int y : dir) {
            for (int x : dir) {
                if (board[i + y][j + x] != '0') {
                    board[i + y][j + x] = '0';
                    cnt++;
                }
            }
        }
    }
    
    return cnt;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int cnt;

    while (1) {
        cnt = check(board);
        if (cnt == 0) break;
        answer += cnt;
        gravity(board);
    }

    cout << answer;

    return answer;
}