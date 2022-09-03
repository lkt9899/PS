#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

string s;
int res;

int main(int argc, char** argv)
{
    fio;
    int test_case;
    int T;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        res = 0;
        cin >> s;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '|' && (s[i-1] == '(' || s[i+1] == ')')) res++;
            else if(s[i] == '(' && s[i+1] == ')') {
                i++; res++;
            }
        }
        cout << "#" << test_case << " " << res << "\n";
    }

    return 0;
}