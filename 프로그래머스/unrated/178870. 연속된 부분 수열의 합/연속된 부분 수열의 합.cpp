#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int size = sequence.size();
    vector<int> answer = {0, size - 1};
    int left = 0;
    int sum = 0;
    for(int right = 0; right < sequence.size(); right++) {
        sum += sequence[right];
        if(sum > k) {
            while(sum > k) {
                sum -= sequence[left];
                left++;    
            }
        }
        if(sum == k && right - left < answer[1] - answer[0]) {
            answer = {left, right};
        }
    }
    
    return answer;
}