#include <vector>
#include <stdio.h>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    if (N == 1) {
        printf("0\n");
    }
    if (N == 2) {
        printf("3\n");
    }
    vector<int> euler(N);
    for (int i = 1; i < N; ++i) {
        euler[i] = i;
    }
    int res = 0;
    for (int i = 2; i < N; ++i) {
        if (euler[i] == i) {
            for (int j = i; j < N; j += i) {
                euler[j] = euler[j] / i * (i - 1);
            }
        }
        res += euler[i] * 2;
    }
    res += 1 + 2;
    printf("%d\n", res);
    return 0;
}
