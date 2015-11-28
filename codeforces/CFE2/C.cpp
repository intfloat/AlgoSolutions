#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    char s[200005];
    scanf("%s", s);
    string val = s;
    vector<int> cnt(26, 0);
    int len = val.size();
    FOR(i, val.size()) {
        ++cnt[val[i] - 'a'];
    }
    vector<int> odd;
    FOR(i, 26) {
        if (cnt[i] % 2) {
            odd.push_back(i);
        }
    }
    if (len % 2) {
        int mid = odd.size() / 2;
        for (int i = 0; i < mid; ++i) ++cnt[odd[i]];
        for (int i = mid + 1; i < (int)odd.size(); ++i) --cnt[odd[i]];
        odd[0] = odd[mid];
    }
    else {
        int mid = odd.size() / 2;
        for (int i = 0; i < mid; ++i) ++cnt[odd[i]];
        for (int i = mid; i < (int)odd.size(); ++i) --cnt[odd[i]];
    }
    string res;
    FOR(i, 26) {
        FOR(j, cnt[i] / 2) {
            res.push_back((char)('a' + i));
        }
    }
    string tmp = res;
    reverse(tmp.begin(), tmp.end());
    if (len % 2) {
        res.push_back((char)(odd[0] + 'a'));
        res += tmp;
    }
    else {
        res += tmp;
    }
    printf("%s\n", res.c_str());
    return 0;
}
