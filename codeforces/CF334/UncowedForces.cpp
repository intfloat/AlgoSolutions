#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int arr[5], wa[5];
    int score[] = {500, 1000, 1500, 2000, 2500};
    for (int i = 0; i < 5; ++i) {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < 5; ++i) {
        scanf("%d", wa + i);
    }
    int hs, hu;
    scanf("%d %d", &hs, &hu);
    double res = hs * 100 - hu * 50;
    for (int i = 0; i < 5; ++i) {
        res += max((0.3 * score[i]), 1.0 * score[i] - score[i] / 250 * arr[i] - 50 * wa[i]);
    }
    printf("%d\n", (int)round(res));
}
