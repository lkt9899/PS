#include <bits/stdc++.h>

using namespace std;

int n, k;
string s[16];
long long int dp[(1 << 15)][100];
int modtens[51];
int modeach[16];

int strmod(const string &s, const int div)
{
    int tmp = 0;
    for (int i = 0; i < s.length(); i++)
    {
        tmp *= 10;
        tmp += (s[i] - '0');
        tmp %= div;
    }

    return tmp;
}

long long GCD(long long lhs, long long rhs)
{
    long long big, small;
    big = max(lhs, rhs);
    small = min(lhs, rhs);

    while (small != 0)
    {
        long long int remainder = big % small;
        big = small;
        small = remainder;
    }

    return big;
}

void run()
{
    for (int curbit = 0; curbit < (1 << n); curbit++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((curbit & (1 << i)) == 0)
            {
                int nextbit = curbit | (1 << i);
                for (int j = 0; j < k; j++)
                {
                    int nextK = ((j * modtens[s[i].length()]) % k + modeach[i]) % k;
                    dp[nextbit][nextK] += dp[curbit][j];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    cin >> k;
    dp[0][0] = 1;
    modtens[0] = 1 % k;

    for (int i = 1; i < 51; i++)
        modtens[i] = (modtens[i - 1] * 10) % k;

    for (int i = 0; i < 16; i++)
        modeach[i] = strmod(s[i], k);

    run();

    long long den = 1, num;
    for (int i = 1; i <= n; i++)
        den *= i;

    num = dp[(1 << n) - 1][0];
    long long gcd = GCD(den, num);
    cout << num / gcd << "/" << den / gcd;

    return 0;
}