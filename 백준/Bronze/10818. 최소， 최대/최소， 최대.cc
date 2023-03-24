#include <cstdio>

int main() {
    int n, m, x = 1000000, y = -1000000;
    scanf("%d ", &n);
    while(n--) {
        scanf("%d", &m);
        if(m < x) x = m;
        if(m > y) y = m;
    }
    printf("%d %d", x, y);
    return 0;
}