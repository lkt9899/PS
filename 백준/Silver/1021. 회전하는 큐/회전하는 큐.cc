#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fio;

    int N, M, ans = 0;
    cin >> N >> M;

    deque<int> dq;
    for(int i = 0; i < N; i++) {
        dq.push_back(i+1);
    }

    for(int i = 0; i < M; i++) {
        int tar;
        cin >> tar;
        auto result = find(dq.begin(), dq.end(), tar);
        if(dq.front() == tar) {
            dq.pop_front();
            continue;
        }

        if(result - dq.begin() > dq.size() / 2) {
            while(dq.front() != tar) {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
            dq.pop_front();
        } else {
            while(dq.front() != tar) {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
            dq.pop_front();
        }
    }

    cout << ans;
    
    return 0;
}