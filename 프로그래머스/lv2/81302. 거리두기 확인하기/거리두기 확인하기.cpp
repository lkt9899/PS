#include <string>
#include <vector>
#include <stack>
#include <queue>
// #include <iostream>

using namespace std;

#define SIZE 5

int rdir[4] = { 0, 1, 0, -1 };
int cdir[4] = { 1, 0, -1, 0 };

struct Pos {
    int _r;
    int _c;
};

int check(vector<string> input) {
    // make graph
    // 2 : wall,  1 : P,  0 : O,  -1 : X
    // change this for testing other inputs
    // string input[5] = {
    //     "POOOP",
    //     "OXXOX",
    //     "OPXPX",
    //     "OOXOX",
    //     "POXXP"
    // };

    // Graph
    int maze[SIZE + 2][SIZE + 2] = {
        {2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 2},
        {2, 2, 2, 2, 2, 2, 2} };

    stack<Pos> ps;      // stack for store P's pos
    Pos p;              // P's axis

    for (int i = 0, ii = 1; i < SIZE; i++, ii++) {
        for (int j = 0, jj = 1; j < SIZE; j++, jj++) {
            // skip empty
            if (input[i][j] == 'O') {
                continue;
            }
            // store axis person exist
            else if (input[i][j] == 'P') {
                maze[ii][jj] = 1;
                p._r = ii;
                p._c = jj;
                ps.push(p);
            }
            // X : -1
            else {
                maze[ii][jj] = -1;
            }
        }
    }

    // cout Graph #can erase this(not necessary)
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            // cout << maze[i][j] << "\t";
        }
        // cout << endl;
    }

    // check by BFS
    queue<Pos> q;
    while (!ps.empty()) {
        p = ps.top();
        ps.pop();

        q.push(p);

        int depth[7][7] = { 0, };       // save Manhattan distance of each axis
        depth[p._r][p._c] = 1;          // start = 1

        while (!q.empty()) {
            p = q.front();
            q.pop();

            int r = p._r, c = p._c;
            for (int i = 0; i < 4; i++) {
                // if not visited
                if (depth[r + rdir[i]][c + cdir[i]] == 0) {
                    // if person exist in distance 2 return 0
                    if (maze[r + rdir[i]][c + cdir[i]] == 1) {
                        return 0;
                    }
                    // if empty keep going
                    else if (maze[r + rdir[i]][c + cdir[i]] == 0) {
                        depth[r + rdir[i]][c + cdir[i]] = depth[r][c] + 1;

                        if (depth[r + rdir[i]][c + cdir[i]] == 3) continue;

                        p._r = r + rdir[i];
                        p._c = c + cdir[i];
                        q.push(p);
                    }
                    // wall or partition continue
                    else continue;
                }
                // if visited continue
                else continue;
            }
        }
    }
    // return true
    return 1;
}

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < places.size(); i++) {
        answer.push_back(check(places[i]));    
    }
    
    
    return answer;
}