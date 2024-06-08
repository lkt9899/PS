#include <vector>

using namespace std;



int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int current = health;
    int lastTime = 0;
    for(auto atk : attacks) {
        // 회복 시간
        int time = atk[0] - lastTime - 1;
        lastTime = atk[0];
        int damage = atk[1];
        
        // 회복
        int success = time / bandage[0];
        current += (success * bandage[2] + time * bandage[1]);
        
        // 최대 체력 확인
        if(current > health) current = health;
        
        // 공격
        current -= damage;

        // 죽으면 미리 끝내기
        if(current <= 0) break;
    }
    if(current <= 0) return -1;
    
    return current;
    
}