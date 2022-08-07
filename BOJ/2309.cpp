#include <bits/stdc++.h>
#define MAX_INPUT 9

using namespace std;

int arr[MAX_INPUT];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int total = 0;

    for (int i = 0; i < MAX_INPUT; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    for (int i = 0; i < MAX_INPUT - 1; i++)
    {
        for (int j = i + 1; j < MAX_INPUT; j++)
        {
            if (total - arr[i] - arr[j] == 100)
            {
                arr[i] = -1;
                arr[j] = -1;
                break;
            }
        }
        if (arr[i] == -1)
            break;
    }

    sort(arr, arr + MAX_INPUT);

    for (int i = 2; i < MAX_INPUT; i++)
    {
        cout << arr[i] << "\n";
    }

    return 0;
}