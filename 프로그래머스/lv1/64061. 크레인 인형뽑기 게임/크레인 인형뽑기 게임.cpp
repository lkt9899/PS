#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> bascket;

    for (int i = 0; i < moves.size(); i++) {
        int j = moves[i] - 1;
        for (int k = 0; k < board.size(); k++) {
            // if exist
            if (board[k][j] != 0) {
                moves[i] = board[k][j];
                // if bascket not empty && already in basket
                if (!bascket.empty() && bascket.back() == board[k][j]) {
                    bascket.pop_back();
                    answer += 2;
                }
                // not yet in bascket
                else
                    bascket.push_back(board[k][j]);
                
                // erase it in board
                board[k][j] = 0;
                break;
    }}}
    
    return answer;
}