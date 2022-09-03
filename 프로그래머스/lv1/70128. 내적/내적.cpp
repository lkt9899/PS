#include <string>
#include <vector>

using namespace std;

int sum(const vector<int>& a, const vector<int>& b) {
    
    int res = 0;
    
    for(int i = 0; i < a.size(); i++) {
        res += (a[i] * b[i]);
    }
    
    return res;
}

int solution(vector<int> a, vector<int> b) {
    int answer = 1234567890;
    
    answer = sum(a, b);
    
    return answer;
}