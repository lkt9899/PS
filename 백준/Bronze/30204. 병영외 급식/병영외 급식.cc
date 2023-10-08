#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

int N, X;
int sum = 0;

int main() {
    fio;

    cin >> N >> X;

    int sum = 0, tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        sum += tmp;
    }

    cout << (sum % X == 0 ? 1 : 0);
}