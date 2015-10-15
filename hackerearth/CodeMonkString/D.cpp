#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
const int MAX_N = 1000005;
char s[MAX_N], t[MAX_N];
int ls, lt;
int main() {
    scanf("%s %s", s, t);
    ls = strlen(s);
    lt = strlen(t);
    int ptr = 0;
    FOR(i, lt) {
        if (ptr == ls) break;
        if (t[i] == s[ptr]) ++ptr;
    }
    printf("%d\n", ptr);
    return 0;
}
