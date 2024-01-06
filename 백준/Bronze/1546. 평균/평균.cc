#include <iostream>

using namespace std;

int main() {
    int N, mx = 0, sum = 0;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num;
        
        cin >> num;
        mx = max(mx, num);
        sum += num;
    }

    cout << (100.0 * sum / mx) / (double)N << "\n";
}
