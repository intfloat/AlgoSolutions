#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<pair<int, char> > res;
bool solve(const vector<int>& num, int base) {
    if ((int)num.size() == 1) {
        return true;
    }
    int mx = *max_element(num.begin(), num.end());
    FOR(i, num.size()) {
        if (num[i] == mx && i - 1 >= 0 && num[i - 1] < mx) {
            FOR(j, i) res.push_back({base + i - j, 'L'});
            for (int j = i + 1; j < (int)num.size(); ++j) res.push_back({base, 'R'});
            return true;
        } else if (num[i] == mx && i + 1 < (int)num.size() && num[i + 1] < mx) {
            for (int j = i + 1; j < (int)num.size(); ++j) res.push_back({base + i, 'R'});
            FOR(j, i) res.push_back({base + i - j, 'L'});
            return true;
        }
    }
    return false;
}
int main() {
    int n, k;
    scanf("%d", &n);
    vector<int> a(n);
    FOR(i, n) scanf("%d", &a[i]);
    scanf("%d", &k);
    vector<int> b(k);
    FOR(i, k) scanf("%d", &b[i]);
    int sm1 = accumulate(a.begin(), a.end(), 0);
    int sm2 = 0;
    FOR(i, k) {
        sm2 += b[i];
        if (sm2 > sm1) {
            printf("NO\n");
            return 0;
        }
    }
    if (sm2 != sm1) {
        printf("NO\n");
        return 0;
    }
    int ptr = 0;
    FOR(i, k) {
        vector<int> num;
        int sm = 0;
        while (ptr < (int)a.size() && sm < b[i]) {
            sm += a[ptr];
            num.push_back(a[ptr]);
            ++ptr;
        }
        if (sm != b[i] || !solve(num, i)) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    FOR(i, res.size()) {
        printf("%d %c\n", res[i].first + 1, res[i].second);
    }
    return 0;
}
