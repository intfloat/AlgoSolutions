#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1000005;
char a[MAX_N], b[MAX_N];
int main() {
    scanf("%s", a);
    scanf("%s", b);
    int lena = strlen(a);
    int lenb = strlen(b);
    int pa = 0, pb = 0;
    while (pa < lena && a[pa] == '0') ++pa;
    while (pb < lenb && b[pb] == '0') ++pb;
    int la = lena - pa, lb = lenb - pb;
    if (la > lb) printf(">\n");
    else if (la < lb) printf("<\n");
    else {
        for (int i = pa; i < lena; ++i) {
            if (a[i] < b[i - pa + pb]) {
                printf("<\n");
                return 0;
            }
            else if (a[i] > b[i - pa + pb]) {
                printf(">\n");
                return 0;
            }
        }
        printf("=\n");
    }
    return 0;
}
