#include <iostream>
#include <algorithm>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

const int K_MAX = 10001;
int L, K, C;
int arr[K_MAX];

int sol(int x) {
    int tmp = 0, from = L, cut = C;

    for (int i = K - 1; i >= 0 && cut > 0; i--) {
        if(from - arr[i] > x) {
            if(arr[i+1] - arr[i] > x)
                return -1;
            cut--;
            from = arr[i + 1];
        }
    }

    if(cut > 0)
        from = arr[0];

    if(from > x)
        return -1;
    else
        return from;
}

int main()
{
    fio;

    cin >> L >> K >> C;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + K);
    arr[K] = -1;
    int j = 0;

    for (int i = 0; i < K; i++) {
        arr[j] = arr[i];
        if(arr[i] != arr[i+1])
            j++;
    }
    K = j;
    arr[K] = L;

    int start = L / (C + 1), end = L, mid, ret;
    while (start < end)
    {
        mid = (start + end) / 2;
        ret = sol(mid);

        if(ret >= 1)
            end = mid;
        else
            start = mid + 1;
    }

    cout << start << ' ' << sol(start);
    return 0;
}