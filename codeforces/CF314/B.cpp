#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    char type;
    int id, n;
    cin >> n;
    set<int> st;
    int res = 0;
    FOR(i, n) {
        cin >> type >> id;
        if (type == '+') {
            st.insert(id);
            res = max(res, (int)st.size());
        }
        else {
            if (st.find(id) == st.end()) {
                ++res;
            }
            else {
                st.erase(id);
            }
        }
    }
    cout << res << endl;
    return 0;
}
