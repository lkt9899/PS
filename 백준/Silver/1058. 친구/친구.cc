#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

const int MAX = 50;
int N, ans;
char arr[MAX][MAX];
int check[MAX][MAX];

int main()
{
    fio;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'Y') {
                check[i][j] = 1;
            } else check[i][j] = (1 << 20);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (check[j][k] > check[j][i] + check[i][k])
                {
                    check[j][k] = check[j][i] + check[i][k];
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            if (check[i][j] <= 2)
                cnt++;
        }
        ans = ans < cnt ? cnt : ans;
    }
    cout << ans;
    return 0;
}