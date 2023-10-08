#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    string s;
    while(true) {
        cin >> s;
        if(s == "0")
            break;

        bool flag = true;
        int i = 0, j = s.length() - 1;
        while(i <= j) {
            if(s[i++] != s[j--]) {
                flag = false;
                break;
            }
        }

        cout << (flag ? "yes\n" : "no\n");
    }
}