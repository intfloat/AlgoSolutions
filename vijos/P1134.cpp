#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int get() {
    string s;
    cin >> s;
    if (s == "A") return 1;
    if (s == "J") return 11;
    if (s == "Q") return 12;
    if (s == "K") return 13;
    if (s == "10") return 10;
    return s[0] - '0';
}

bool solve(vector<double> v) {
    if (v.size() == 1) return (fabs(v[0] - 24) < 1e-6);
    FOR(i, v.size()) FOR(j, v.size()) {
        if (i == j) continue;
        vector<double> cur, arg;
        FOR(k, v.size()) {
            if (k != i && k != j) cur.push_back(v[k]);
        }
        arg = cur; arg.push_back(v[i] + v[j]);
        if (solve(arg)) return true;
        arg = cur; arg.push_back(v[i] - v[j]);
        if (solve(arg)) return true;
        arg = cur; arg.push_back(v[i] * v[j]);
        if (solve(arg)) return true;
        if (v[j] != 0 ) {
            arg = cur; arg.push_back(v[i] / v[j]);
            if (solve(arg)) return true;
        }
    }
    return false;
}

int main() {
    vector<double> numbers;
    FOR(i, 4) numbers.push_back(get());
    assert(numbers.size() == 4);
    if (solve(numbers)) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
