#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

int N;

int main() {
    fio;
    cin >> N;
    cout << (N % 2 == 0 ? "SK\n" : "CY\n");
    return 0;
}