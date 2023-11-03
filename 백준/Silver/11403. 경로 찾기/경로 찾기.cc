#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int MAX = 100;
int N;
int adj[MAX][MAX];

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }
}

void FW() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (adj[i][k] && adj[k][j]) adj[i][j] = 1;
            }
        }
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

void sol() {
    FW();
    print();
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