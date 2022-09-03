#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    
    while(!completion.empty()) {
        if(participant.back() == completion.back()) {
            completion.pop_back();
            participant.pop_back();
        }
        else {
            break;
        }
    }
    
    return participant.back();
}