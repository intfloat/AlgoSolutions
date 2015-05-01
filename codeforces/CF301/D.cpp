#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    map<tuple<int, int, int>, double> prev, cur;
    map<tuple<int, int, int>, double>::iterator it;
    prev[make_tuple(a, b, c)] = 1.0;
    while (true) {
        int ok = true;
        cur.clear();
        for (it = prev.begin(); it != prev.end(); ++it) {
            tuple<int, int, int> val = it->first;
            int a = get<0>(val), b = get<1>(val), c = get<2>(val);
            double p = it->second;
            if (a + b + c == max(a, max(b, c))) {
                cur[val] = p;
                continue;
            }
            ok = false;
            int total = a * b + b * c + c * a;
            if (a > 0 && b > 0) cur[make_tuple(a, b - 1, c)] += (a * b * p) / total;
            if (b > 0 && c > 0) cur[make_tuple(a, b, c - 1)] += (b * c * p) / total;
            if (c > 0 && a > 0) cur[make_tuple(a - 1, b, c)] += (a * c * p) / total;
        }
        if (ok) break;
        prev = cur;
    }
    vector<double> res(3, 0);
    for (it = cur.begin(); it != cur.end(); ++it) {
        tuple<int, int, int> val = it->first;
        int a = get<0>(val), b = get<1>(val), c = get<2>(val);
        if (a != 0) res[0] += it->second;
        else if (b != 0) res[1] += it->second;
        else if (c != 0) res[2] += it->second;
    }
    // cout << "DEBUG: " << accumulate(res.begin(), res.end(), 0.0) << endl;
    cout << fixed << setprecision(10);
    FOR(i, 3) cout << res[i] << " ";
    cout << endl;
    return 0;
}
