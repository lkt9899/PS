#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    int t, r;
    
    cin >> t;
    while(t--) {
        cin >> r >> s;
        for(int i = 0; i < s.length(); i++) 
            for(int j = 0; j < r; j++)
                cout << s[i];
        cout << "\n";
    }
    
    return 0;
}