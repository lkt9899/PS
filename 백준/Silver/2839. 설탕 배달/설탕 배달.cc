#include <iostream>

using namespace std;

int main() {
    int N, ans;
    cin >> N;
    ans = N / 5;
    
    if (N == 4 || N == 7) cout << -1;
    else if (N % 5 == 0) cout << ans;
    else if (N % 5 == 1 || N % 5 == 3) cout << ans + 1;
    else if (N % 5 == 2 || N % 5 == 4) cout << ans + 2;
    
    return 0;
}