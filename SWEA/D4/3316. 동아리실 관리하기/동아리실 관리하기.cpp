#include <iostream>
#include <string>
#include <cstring>
 
#define MAX 10000
#define MOD 1000000007
 
int DP[MAX][16];
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T; cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string s; cin >> s;
        int len = s.length();
        memset(DP, 0, sizeof(DP));
         
        for(int i = 0; i < len; i++) {
            int admin = 1 << (s[i] - 'A');
             
            for(int j = 1; j < 16; j++) {
                if(i==0) {
                    if((j & admin) && (j & 1)) {
                        DP[i][j] = 1;
                    }
                }
                else {
                    if(DP[i-1][j]) {
                        for(int k = 1; k < 16; k++) {
                            if((k & j) && (k & admin)) {
                                DP[i][k] += DP[i-1][j];
                                DP[i][k] %= MOD;
                }}}}
            }
        }
         
        int res = 0;
        for(int i = 1; i < 16; i++) {
            res += DP[len-1][i];
            res %= MOD;
        }
        printf("#%d %d\n", test_case, res);
    }
    return 0;
}