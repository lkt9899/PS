#include <iostream>

using namespace std;

int T, x, y, cur, ans;

void init() {
    cur = 0;
    ans = 0;
    cin >> x >> y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for(int test_case = 0; test_case < T; test_case++) {
        init();
        while(x != y) {
            cur++;
            if(y - x > cur * 3) {
                x += cur;
                y -= cur;
                ans += 2;
            }
            else {
                if(y - x <= cur) ans++;
                else if(y - x <= cur * 2) ans += 2;
                else ans += 3;
                break;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}