#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

const int MAX = 101;
int N, K;
int sw[MAX];
pii student[MAX];

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> sw[i];
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> student[i].first >> student[i].second;
    }
}

void toggle(int gen, int num)
{
    if (gen == 1) {
        for (int i = num; i <= N; i += num) {
            sw[i] ^= 1;
        }
    }
    else {
        int idx = num;
        sw[idx] ^= 1;
        int cnt = 1;
        while (1) {
            if (idx - cnt <= 0 || idx + cnt > N)
                break;
            if (sw[idx + cnt] == sw[idx - cnt]) {
                sw[idx + cnt] ^= 1;
                sw[idx - cnt] ^= 1;
                cnt++;
            }
            else
                break;
        }
    }
}

void sol() {
    int gen, num;
    for (int i = 0; i < K; i++) {
        gen = student[i].first;
        num = student[i].second;

        toggle(gen, num);
    }

    for (int i = 1; i <= N; i++) {
        cout << sw[i] << " ";
        if (i % 20 == 0)
            cout << "\n";
    }
}

void run() {
    input();
    sol();
}

int main() {
    fio;
    run();
    return 0;
}