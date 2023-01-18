#include <stdio.h>

int main()
{
    int N, L;
    int t = 0;

    scanf("%d %d", &N, &L);
    while(t <= N && L <= 100) {
        t = L * (L-1) / 2;
        if((N - t) % L == 0 && t <= N) {
            for(int i = 0; i < L; i++) {
                printf("%d ", (N - t) / L + i);
            }
            return 0;
        }
        L++;
    }
    printf("-1");

    return 0;
}