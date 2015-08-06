#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
int n, k, a, d, x, m;
inline int get(int left, int right) {
    return (right - left + 1 + 1) / (a + 1);
}
int main() {
    scanf("%d %d %d %d", &n, &k, &a, &m);
    set<point> st;
    set<point>::iterator it;
    st.insert(make_pair(1, n));
    int mx = get(1, n);
    FOR(i, m) {
        scanf("%d", &x);
        it = st.upper_bound(make_pair(x, n + 1));
        if (it == st.begin()) continue;
        --it;
        point cur = *it;
        d = 0;
        if (x >= cur.first && x <= cur.second) {
            st.erase(it);
            d = -1 * get(cur.first, cur.second);
            if (x - 1 >= cur.first) {
                d += get(cur.first, x - 1);
                st.insert(make_pair(cur.first, x - 1));
            }
            if (x + 1 <= cur.second) {
                d += get(x + 1, cur.second);
                st.insert(make_pair(x + 1, cur.second));
            }
        }
        mx += d;
        if (mx < k) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
