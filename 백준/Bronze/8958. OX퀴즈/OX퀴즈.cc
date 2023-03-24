#include <cstdio>

int main() {
    int t, ans, score;
    char c;
    scanf("%d ", &t);
    while(t--) {
        score = 0;
        ans = 0;
        while(1) {
            scanf("%c", &c);
            if(c == '\n') break;

            if(c == 'O') ans += ++score;
            else score = 0;
        }
        printf("%d\n", ans);
    }

    return 0;
}