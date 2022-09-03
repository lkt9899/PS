#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int>::iterator itr, itr2;
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++)
            answer.push_back(numbers[i] + numbers[j]);
    }
    
    itr = answer.begin();
    sort(answer.begin(), answer.end());
    while (itr != answer.end()-1) {
        itr2 = itr + 1;
        if (*itr != *itr2) {
            itr++;
            continue;
        }
        else {
            answer.erase(itr2);
        }
    }
    return answer;
}