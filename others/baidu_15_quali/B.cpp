#include <iostream>
#include <string.h>
#include <stdio.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 100005;
char s[MAX_N], res[MAX_N];
void solve() {
    int col, ptr = 0;
    getchar();
    gets(s);
    scanf("%d", &col);
    int len = strlen(s);
    int md = len % col, row = len / col;
    for (int i = 0; i < row; ++i) {
        int pos = i;    
        for (int j = 0; j < col; ++j) {
            res[ptr++] = s[pos];
            if (j < md) pos += row + 1;
            else pos += row;
        }
    }
    if (md) {
        int pos = row;
        FOR(i, md) {
            res[ptr++] = s[pos];
            pos += row + 1;
        }
    }
    res[ptr] = '\0';
    printf("%s\n", res);
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
