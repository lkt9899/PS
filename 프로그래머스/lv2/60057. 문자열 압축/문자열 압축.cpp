#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int cutstr(string s, int size) {
    vector<string> ar = {};
    string tmp, res;
    int cnt = 1;
    
    for(int i = 0; i < s.length()-size; i += size) {
        if(s.substr(i, size) != s.substr(i+size, size)) {
            if(cnt > 1) {
                res += (to_string(cnt) + s.substr(i, size));
                cnt = 1;
            }
            else {
                res += s.substr(i, size);
            }
        }
        
        else if(s.substr(i, size) == s.substr(i+size, size)) {
            cnt++;
        }
        
        if(i + size >= s.length() - size) {
            if(cnt > 1) {
                res += (to_string(cnt) + s.substr(i, size));
            }
            else {
                res += s.substr(i+size, size);
            }
        }
    }
    return res.length();
}

int solution(string s) {
    int answer = s.length();
    
    for(int i = 1; i < s.length(); i++) {
        answer = min(answer, cutstr(s ,i));   
    }
    
    return answer;
}