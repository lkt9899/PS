#include <cmath>

using namespace std;

double getX(int y, int r) {
    return sqrt(pow(r, 2) - pow(y, 2));
}

int count(int x1, int x2) {
    return (x2 - x1) + 1;
}

long long solution(int r1, int r2) {
    long long ans = 0;
    
    for(int y = r2; y > 0; y--) {
        int max_x = floor(getX(y, r2));
        if(y > r1) {
            ans += count(0, max_x);
        } else {
            ans += count(ceil(getX(y, r1)), max_x);
        }
    }
    
    return ans * 4;
}