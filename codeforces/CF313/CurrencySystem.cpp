#include <stdio.h>
using namespace std;
int main() {
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        if (num == 1) {
            printf("-1\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}
