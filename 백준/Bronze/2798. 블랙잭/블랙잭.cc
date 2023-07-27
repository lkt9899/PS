#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int MAX = 100;
int N, M, ans;
int arr[MAX];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void sol()
{
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum > ans && sum <= M)
                    ans = sum;
            }
        }
    }
    cout << ans;
}

void run()
{
    input();
    sol();
}

int main()
{
    fio;
    run();
    return 0;
}