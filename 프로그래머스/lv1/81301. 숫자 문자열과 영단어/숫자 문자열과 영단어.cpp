#include <string>
#include <vector>

using namespace std;

vector<string> num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


int solution(string s) {
    int answer = 0;
    int i;
    string ans = "";
    string tmp = "";
    
    for(char c : s) {
        if(c - 48 < 10) {
            ans += c;  
            continue;
        }
            
        tmp += c;
        for(i = 0; i < num.size(); i++) {
            if(tmp == num[i]) {
                ans += (i + 48);
                tmp = "";
            }
        }
    }
    
    answer = atoi(ans.c_str());
    
    return answer;
}