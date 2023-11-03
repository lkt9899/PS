#include <iostream>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100
using namespace std;

int main() {
    fio;
    int N;
    cin >> N;
    int adj[N][N];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> adj[i][j];
    
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adj[i][j] |= (adj[i][k] & adj[k][j]);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    return 0;
}