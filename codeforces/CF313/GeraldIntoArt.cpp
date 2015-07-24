#include <stdio.h>
using namespace std;
int h, w, h1, h2, w1, w2;
bool check(int x, int y, int hh, int ww) {
    return x + hh <= h && y + ww <= w;
}
int main() {
    scanf("%d %d", &h, &w);
    scanf("%d %d %d %d", &h1, &w1, &h2, &w2);
    if (check(0, 0, h1, w1)) {
        if (check(h1, 0, h2, w2) || check(h1, 0, w2, h2)
            || check(0, w1, h2, w2) || check(0, w1, w2, h2)) {
            printf("YES\n");
            return 0;
        }
    }
    if (check(0, 0, w1, h1)) {
        if (check(w1, 0, h2, w2) || check(w1, 0, w2, h2)
            || check(0, h1, h2, w2) || check(0, h1, w2, h2)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
