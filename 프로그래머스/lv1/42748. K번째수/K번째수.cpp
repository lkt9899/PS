#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<int> arr, vector<int> com) {
    int i = com[0] - 1, j = com[1], k = com[2] - 1;
    
    vector<int> res;
    
    for(i; i < j; i++) {
        res.push_back(arr[i]);
    }
    sort(res.begin(), res.end());
    
    return res[k];
}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++) {
        answer.push_back(check(array, commands[i]));
    }
    
    return answer;
}