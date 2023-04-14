#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end());
    
    int idx = 0;
    int max = targets[0][1];
    while(idx != targets.size()) {
        if(targets[idx][0] < max) {
            if(targets[idx][1] < max) max = targets[idx][1];
        }
        else {
            max = targets[idx][1];
            answer++;
        }
        idx++;
    }
    
    return answer;
}