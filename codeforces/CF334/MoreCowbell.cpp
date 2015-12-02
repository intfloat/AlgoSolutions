#include <bits/stdc++.h>
using namespace std;
int n, k;
multiset<int> st;
inline bool ok(int mid) {
    int cnt = 0;
    while (!st.empty()) {
        int tp = *(st.begin());
        st.erase(st.begin());
        if (tp > mid) return false;
        if (st.empty() || tp + (*st.begin()) > mid) ++cnt;
        else {
            auto it = st.upper_bound(mid - tp);
            --it;
            st.erase(it);
            ++cnt;
        }
    }
    return (cnt <= k);
}
int main() {
    scanf("%d %d", &n, &k);
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
    }
    int l = 1, r = 2000000;
    while (l < r) {
        int mid = (l + r) / 2;
        st.clear();
        for (int i = 0; i < n; ++i) {
            st.insert(s[i]);
        }
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
