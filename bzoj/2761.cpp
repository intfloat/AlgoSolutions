#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
int n, t;
inline void solve() {
    scanf("%d", &n);
    set<int> st;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if (st.find(t) == st.end()) {
            st.insert(t);
            res.push_back(t);
        }
    }
    printf("%d", res[0]);
    for (int i = 1; i < res.size(); ++i) {
        printf(" %d", res[i]);
    }
    printf("\n");
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
