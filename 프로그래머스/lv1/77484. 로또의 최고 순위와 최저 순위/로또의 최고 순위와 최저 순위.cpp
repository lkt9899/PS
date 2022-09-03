#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int max = 0, min = 0, zero = 0, same = 0;
    // check zeros
    for(int a : lottos) {
        if(a == 0)
            zero++;
    }
    
    for(int i = 0; i < win_nums.size(); i++) {
        for(int j = 0; j < lottos.size(); j++) {
            if(lottos[j] && lottos[j] == win_nums[i]) {
                same++;
                break;
            }
        }
    }
    
    min = (same >= 2) ? 7 - same : 6;
    max = (zero == 6)? 1 : min - zero;
    
    answer.push_back(max);
    answer.push_back(min);
    return answer;
}