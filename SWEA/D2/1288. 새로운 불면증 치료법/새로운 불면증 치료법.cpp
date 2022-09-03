#include<iostream>
 
using namespace std;
 
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test_case;
    int N, T;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int nN = 0;
        int tmp = 0;
        int chk = 0;
        cin >> N;
         
        while(chk != (1 << 10) - 1) {
            nN += N;
            tmp = nN;
            while(tmp > 0) {
                chk |= 1 << (tmp % 10);
                tmp /= 10;
            } 
        }
         
        cout << "#" << test_case << " " << nN << "\n";
    }
    return 0;
}