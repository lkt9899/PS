#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);

    string t;
    int ans = 0;
    while (ss >> t) ans++;

    cout << ans;
}