#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
int main() {
    int n, h, pos;
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    vector<point> arr;
    FOR(i, n) {
        scanf("%d", &h);
        arr.push_back({h, i});
    }
    vector<int> res(n);
    set<int> st;
    st.insert(0);
    st.insert(n - 1);
    res[0] = res[n - 1] = 1;
    sort(arr.begin() + 1, arr.end() - 1);
    for (int i = 1; i < n - 1; ++i) {
        h = arr[i].first;
        pos = arr[i].second;
        st.insert(pos);
        res[pos] = h;
        auto it = st.find(pos);
        --it;
        res[pos] = min(res[pos], res[*it] + pos - *it);
        ++it; ++it;
        res[pos] = min(res[pos], res[*it] + *it - pos);
    }
    printf("%d\n", *max_element(res.begin(), res.end()));
    return 0;
}
