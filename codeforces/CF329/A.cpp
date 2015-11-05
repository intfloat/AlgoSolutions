#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline bool ok(string& str, char i, char j) {
    FOR(k, str.size()) {
        if (str[k] != i && str[k] != j) return false;
    }
    return true;
}
int main() {
    int N;
    scanf("%d", &N);
    vector<string> arr;
    char s[1005];
    FOR(i, N) {
        scanf("%s", s);
        arr.push_back(string(s));
    }
    int res = 0;
    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = i + 1; j <= 'z'; ++j) {
            int cur = 0;
            FOR(k, N) {
                if (ok(arr[k], i, j)) cur += arr[k].size();
            }
            res = max(res, cur);
        }
    }
    printf("%d\n", res);
    return 0;
}
