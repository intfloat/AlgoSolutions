#include <stdio.h>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <cassert>
using namespace std;
typedef pair<int, int> point;
struct Node {
    int x, y1, y2;
    bool left;
    Node(int _x, int _y1, int _y2, bool _l): x(_x), y1(_y1), y2(_y2), left(_l) {}
};
bool cmp(const Node& n1, const Node& n2) {
    return n1.x < n2.x;
}
int main() {
#ifndef DEBUG
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);
#endif
    int N, x1, x2, y1, y2;
    scanf("%d", &N);
    vector<Node> arr;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        arr.push_back(Node(x1, y1, y2, true));
        arr.push_back(Node(x2, y1, y2, false));
    }
    sort(arr.begin(), arr.end(), cmp);
    set<point> st;
    set<point>::iterator it;
    int res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (st.empty()) {
            st.insert(make_pair(arr[i].y2, arr[i].y1));
            ++res;
            continue;
        }
        if (!arr[i].left) {
            point t = make_pair(arr[i].y2, arr[i].y1);
            it = st.find(t);
            if (it != st.end())
                st.erase(it);
            continue;
        }
        it = st.upper_bound(make_pair(arr[i].y2, -1));
        if (it == st.end() || (*it).second >= arr[i].y2) {
            ++res;
            st.insert(make_pair(arr[i].y2, arr[i].y1));
        }
        else {
            assert(arr[i].y2 <= (*it).first && arr[i].y1 >= (*it).second);
        }
    }
    printf("%d\n", res);
    return 0;
}
