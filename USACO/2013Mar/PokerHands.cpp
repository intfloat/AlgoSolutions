#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> point;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int N;
    scanf("%d", &N);
    vector<point> arr;
    vector<int> val(N + 2);
    val[0] = val[N + 1] = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &val[i]);
        arr.push_back(make_pair(val[i], i));
    }
    sort(arr.begin(), arr.end());
    set<int> st;
    st.insert(0);
    st.insert(N + 1);
    set<int>::iterator it1, it2;
    long long res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int v = arr[i].first;
        int pos = arr[i].second;
        it1 = st.upper_bound(pos);
        it2 = it1;
        --it2;
        res += v - max(val[*it1], val[*it2]);
        st.insert(pos);
    }
    printf("%lld\n", res);
    return 0;
}
