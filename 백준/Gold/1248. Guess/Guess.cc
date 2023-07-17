#include <iostream>

using namespace std;

const int MAX = 10;
int N;
char sign[MAX][MAX];
int arr[MAX];

bool check(int idx)
{
    int sum = 0;
    for (int i = idx; i >= 0; i--)
    {
        sum += arr[i];
        if (sign[i][idx] == '+' && sum <= 0)
            return false;
        if (sign[i][idx] == '-' && sum >= 0)
            return false;
        if (sign[i][idx] == '0' && sum != 0)
            return false;
    }

    return true;
}

void dfs(int cnt)
{
    if (cnt == N)
    {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        exit(0);
    }

    for (int i = -MAX; i <= MAX; i++)
    {
        arr[cnt] = i;
        if (check(cnt))
            dfs(cnt + 1);
    }
}

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            cin >> sign[i][j];
        }
    }
}

void run()
{
    input();
    dfs(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    run();

    return 0;
}