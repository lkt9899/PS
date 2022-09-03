#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    stack<int> num;
    
    while(n > 3) {
        int tmp = n % 3;
        if(tmp == 0) {
            num.push(3);
            n = n / 3 - 1;
        }
        else {
            num.push(n % 3);
            n /= 3;
        }
    }
    num.push(n);
    
    while(!num.empty()) {
        int tmp = num.top();
        if(tmp == 3)
            answer += "4";
        else
            answer += to_string(tmp);
        num.pop();
    }
    return answer;
}