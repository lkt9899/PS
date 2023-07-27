#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int MAX = 50;
int ans, N, cnt;
char arr[MAX];

void init()
{
    ans = 0;
    cnt = 0;
}

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void sol()
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 'L')
        {
            cnt++;
        }
    }
    if (cnt > 2)
    {
        cout << N - cnt / 2 + 1;
    }
    else
    {
        cout << N;
    }
}
void run()
{
    init();
    input();
    sol();
}

int main()
{
    fio;
    run();
    return 0;
}