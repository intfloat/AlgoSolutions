#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char s[30005];
int main() {
    gets(s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') continue;
        if (i - 1 < 0 || s[i - 1] == ' ') {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = 'A' + (s[i] - 'a');
            }
        }
    }
    printf("%s\n", s);
    return 0;
}
