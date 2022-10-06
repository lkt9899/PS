#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int answer = 0;
int i = 0;
int arr1[26] = {0, };
int arr2[26] = {0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;

    while(s1[i] || s2[i]) {
        if(i < s1.size())   arr1[(int)(s1[i] - 97)]++;
        if(i < s2.size())   arr2[(int)(s2[i] - 97)]++;
        i++;
    }
    for(int i = 0; i < 26; i++) {
        answer += (abs(arr1[i] - arr2[i]));
    }
    cout << answer;

    return 0;
}