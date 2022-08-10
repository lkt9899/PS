#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main(int argc, char **argv)
{
    fio;
    int test_case;
    int T;

    freopen("14692.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;

        cout << "#" << test_case << " " << (N % 2 ? "Bob" : "Alice") << "\n";
    }
    return 0;
}