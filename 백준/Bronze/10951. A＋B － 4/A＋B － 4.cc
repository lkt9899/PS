#include <cstdio>

int main() {
    int a, b;
    while(1) {
        if(scanf("%d %d", &a, &b) == -1) break;
        printf("%d\n", a+b);
    }
}