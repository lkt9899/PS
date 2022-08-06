#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> make_table(string S) {
    int pattern_size = S.size();
    vector<int> table(pattern_size, 0);
    int j = 0;
    for(int i = 1; i < pattern_size; i++) {
        while(j > 0 && S[i] != S[j]) {
            j = table[j-1];
        }

        if(S[i] == S[j]) {
            table[i] = ++j;
        }   
    }

    return table;
}

int KMP(string B, string S) {
    vector<int> table = make_table(S);
    int B_size = B.size();
    int S_size = S.size();
    int j = 0, ans = 0;

    for(int i = 0; i < B_size; i++) {
        while(j > 0 && B[i] != S[j]) {
            j = table[j-1];
        }
        if(B[i] == S[j]) {
            if(j == S_size - 1) {
                ans++;
                j = table[j];
            }
            else j++;
        }
    }

    return ans;
}

int main(int argc, char** argv)
{
    int test_case;
    int ans, T;
    string B, S;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> B >> S;
        ans = KMP(B, S);
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}