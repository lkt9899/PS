#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M, L, ans;
int arr[51];

void init()
{
    fill(&arr[0], &arr[51], 0);
}

void input()
{
    cin >> N >> M >> L;
}

void sol()
{
    int cnt = 0;
    int num = 1;
    arr[num] = 1;
    while (arr[num] < M)
    {
        if (arr[num] % 2 == 1)
        {
            num += L;
            if (num > N)
                num %= N;
        }
        else
        {
            num -= L;
            if (num <= 0)
                num += N;
        }
        arr[num]++;
        cnt++;
    }
    cout << cnt;
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