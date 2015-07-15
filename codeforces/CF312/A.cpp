#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> point;
int acc(vector<point>& arr, int sz) {
    int ret = 0;
    FOR(i, sz) {
        ret += arr[i].second;
    }
    return ret;
}
int main() {
    int n, res, x, apple;
    cin >> n;
    vector<point> left, right;
    FOR(i, n) {
        cin >> x >> apple;
        if (x < 0) {
            left.push_back(make_pair(x, apple));
        }
        else {
            right.push_back(make_pair(x, apple));
        }
    }
    sort(right.begin(), right.end());
    sort(left.begin(), left.end(), greater<point>());
    if (left.size() == right.size()) {
        res = acc(left, left.size()) + acc(right, right.size());
    }
    else if (left.size() < right.size()) {
        res = acc(left, left.size()) + acc(right, left.size() + 1);
    }
    else {
        res = acc(left, right.size() + 1) + acc(right, right.size());
    }
    cout << res << endl;
    return 0;
}
