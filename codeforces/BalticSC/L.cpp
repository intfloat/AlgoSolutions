#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char s[100005];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int sad = 0, happy = 0;
    FOR(i, n) {
        if (s[i] != ':') continue;
        if (i - 1 >= 0) {
            happy += (s[i - 1] == '(');
            sad += (s[i - 1] == ')');
        }
        if (i + 1 < n) {
            sad += (s[i + 1] == '(');
            happy += (s[i + 1] == ')');
        }
    }
    if (happy > sad) printf("HAPPY\n");
    else if (happy < sad) printf("SAD\n");
    else printf("BORED\n");
    return 0;
}
