#include<iostream>
using namespace std;
 
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test_case;
    int T;  cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, M;   cin >> N >> M;
        int chk = (1 << N) - 1;
        int tmp = chk;
 
        chk &= M;
        cout << "#" << test_case << " ";
        if(chk == tmp) cout << "ON\n";
        else cout << "OFF\n";
    }
    return 0;
}