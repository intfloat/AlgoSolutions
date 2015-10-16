#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
multiset<int> st, tmp;
int main() {
    int n;
    scanf("%d", &n);
    vector<pii> arr(n);
    FOR(i, n) scanf("%d %d", &arr[i].second, &arr[i].first);
    sort(arr.begin(), arr.end());
    ll pre = 0, suf = 0;
    FOR(i, n) {
        st.insert(arr[i].second);
        pre += arr[i].second;
    }
    ll res = pre;
    int ptr = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        int p = ptr;
        while (p >= 0 && arr[p].first == i + 1) {
            suf += arr[p].second;
            auto it = st.find(arr[p].second);
            if (it != st.end()) {
                pre -= arr[p].second;
                st.erase(it);
            }
            else {
                it = tmp.find(arr[p].second);
                tmp.erase(it);
            }
            --p;
        }
        ptr = p;
        int rem = i - (n - 1 - p);
        if (rem < 0) continue;
        while ((int)st.size() > rem) {
            int val = *st.rbegin();
            pre -= val;
            st.erase(st.find(val));
            tmp.insert(val);
        }
        while ((int)st.size() < rem) {
            int val = *tmp.begin();
            pre += val;
            tmp.erase(tmp.begin());
            st.insert(val);
        }
        res = min(res, pre + suf);
    }
    printf("%lld\n", res);
    return 0;
}
