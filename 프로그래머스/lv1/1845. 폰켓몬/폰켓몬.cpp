#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 1;
    vector<int> po;
    
    sort(nums.begin(), nums.end());
    
    po.push_back(nums[0]);
    for(int n : nums) {
        if(n != po.back()) {
            po.push_back(n);
            answer++;
        }
        if(po.size() == nums.size() / 2)
            break;
    }
    
    return answer;
}