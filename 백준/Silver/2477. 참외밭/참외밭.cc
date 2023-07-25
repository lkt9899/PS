#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

int K, ans;
pair<int, int> arr[6];

void input()
{
    cin >> K;
    int w, h;
    for (int i = 0; i < 6; i++)
    {
        int dir, len;
        cin >> dir >> len;
        arr[i] = {dir, len};
    }
}

void sol()
{
    int m1 = 0, i1, m2 = 0, i2;
    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0)
        {
            if (m1 < arr[i].second)
            {
                m1 = arr[i].second;
                i1 = i;
            }
        }
        else
        {
            if (m2 < arr[i].second)
            {
                m2 = arr[i].second;
                i2 = i;
            }
        }
    }
    i1 = (i1 + 3) % 6;
    i2 = (i2 + 3) % 6;
    ans = m1 * m2 - arr[i1].second * arr[i2].second;
    cout << ans * K;
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