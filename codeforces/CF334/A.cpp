#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 100005;
char s[MAX_N];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    string val = s;
    vector<pii> arr;
    int ptr = 0;
    bool three = false;
    vector<int> two;
    while (ptr < n) {
        int l = ptr;
        while (ptr < n && val[ptr] == val[l]) ++ptr;
        arr.push_back({l, ptr - l});
        if (ptr - l >= 3) three = true;
        else if (ptr - l == 2) two.push_back(l);
    }
    int res = arr.size();
    if (three) res += 2;
    else if ((int)two.size() >= 2) res += 2;
    else if ((int)two.size() == 1) {
        res += 1;
    }
    printf("%d\n", res);
    return 0;
}
