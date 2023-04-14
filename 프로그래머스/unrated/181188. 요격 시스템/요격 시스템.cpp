#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void print(vector<vector<int>> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << "[" << v[i][0] << ", " << v[i][1] << "] ";
    }
}

bool cmp(vector<int> v1, vector<int> v2) {
    return v1[0] == v2[0] ? (v1[1] - v1[0]) < (v2[1] - v2[0]) : v1[0] < v2[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
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
    
    return answer + 1;
}