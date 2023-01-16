#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

#define MAX_N 20001

bool Comp(string s1, string s2) {
    if(s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }
    else
        return s1 < s2;
}


int main()
{
    fio;
    
    string words[MAX_N];
    int N;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> words[i];
    }

    sort(words, words + N, Comp);

    for(int i = 0; i < N; i++) {
        if(words[i] == words[i-1]) continue;
        cout << words[i] << "\n";
    }

    return 0;
}