#include <iostream>

using namespace std;

int main() {
    int T, H, W, N;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int f, b;
        cin >> H >> W >> N;
        b = N / H + 1;
        f = N % H;
        if(f == 0) {
            f = H;
            b--;
        }
        
        cout << f;
        if(b < 10)
            cout << 0;
        cout << b << "\n";
    }
}