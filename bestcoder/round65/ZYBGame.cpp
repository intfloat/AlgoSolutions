#include <stdio.h>
using namespace std;
int main() {
    int T, N;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &N);
        if (N % 2) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
