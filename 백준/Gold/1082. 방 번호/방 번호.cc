#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 10;
int N, M;
int arr[MAX];
vector<pair<int, int>> v;
string ans = "";

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        v.push_back({arr[i], i});
    }
    cin >> M;

    sort(v.begin(), v.end());

    if (N == 1)
    {
        cout << 0;
        return 0;
    }

    if (v[0].second != 0)
    {
        int cnt = M / v[0].first;
        for (int i = 0; i < cnt; i++)
            ans += v[0].second + '0';
        M -= cnt * v[0].first;
    }
    else
    {
        int m = M - v[1].first;
        if (m < 0)
        {
            cout << 0;
            return 0;
        }
        ans += v[1].second + '0';
        int cnt = m / v[0].first;
        for (int i = 0; i < cnt; i++)
        {
            ans += v[0].second + '0';
        }
        M = m - cnt * v[0].first;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        int flag = 0;
        for (int j = N - 1; j >= 0; j--)
        {
            if (M + arr[ans[i] - '0'] - arr[j] >= 0)
            {
                M -= arr[j] - arr[ans[i] - '0'];
                ans[i] = j + '0';
                flag = 1;
            }

            if (flag)
                break;
        }
        if (!flag)
            break;
    }

    cout << ans;
    return 0;
}