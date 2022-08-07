#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main(int argc, char** argv)
{
    fio;
    int test_case;
    int T = 10;
    
    freopen("1233.txt", "r", stdin);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int ans = 1;
        int N; cin >> N;
        for(int i = 1; i <= N; i++) {
            int left, right;
            char data; cin >> i >> data;
            if(i <= N / 2) {
                if(i == N / 2 && N % 2 == 0) cin >> left;
                else cin >> left >> right;

                if(data >= '0' && data <= '9') ans = 0;
            }
            else {
                if(data <= '0' && data >= '9') ans = 0;
            }
        }
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}