#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    char* s = new char[n + 1];
    scanf("%s", s);
    int one = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++zero;
        }
        else {
            ++one;
        }
    }
    printf("%d\n", abs(one - zero));
    return 0;
}
