#include <stdio.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
        if (i > 0 && i % 2) {
            arr[i] = (arr[i] + arr[0]) % n;
            if (arr[i] != i) {
                printf("No\n");
                return 0;
            }
        }
        else if (i > 0 && i % 2 == 0) {
            arr[i] = (arr[i] - arr[0] + n) % n;
            if (arr[i] != i) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}
