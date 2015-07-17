#include <bits/stdc++.h>
using namespace std;
inline void solve() {
    int n, cnt, penalty;
    string name;
    cin >> n;
    vector<tuple<int, int, string> > arr;
    for (int i = 0; i < n; ++i) {
        cin >> name >> cnt >> penalty;
        arr.emplace_back(make_tuple(-cnt, penalty, name));
    }
    sort(arr.begin(), arr.end());
    cout << get<2>(arr[0]) << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
