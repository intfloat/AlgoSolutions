#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline void solve() {
    int n, res = 0;
    scanf("%d", &n);
    vector<int> arr(n);
    set<int> st;
    FOR(i, n) {
        scanf("%d", &arr[i]);
        st.insert(i + 1);
    }
    FOR(i, n) {
        auto it = st.begin();
        if (*it == arr[i]) {
            st.erase(it);
            continue;
        }
        ++it;
        if (*it == arr[i]) {
            st.erase(it);
            ++res;
            continue;
        }
        ++it;
        if (*it == arr[i]) {
            st.erase(it);
            res += 2;
            continue;
        }
        printf("Too chaotic\n");
        return;
    }
    printf("%d\n", res);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
