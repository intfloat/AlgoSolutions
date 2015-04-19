#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const double pi = atan(1) * 4;
void solve() {
    vector<double> xs, ys;
    int N;
    cin >> N;
    xs.resize(N); ys.resize(N);
    FOR(i, N) cin >> xs[i] >> ys[i];    
    FOR(i, N) {
        vector<double> degree;
        FOR(j, N) {
            if (i == j) continue;            
            degree.push_back(atan2(ys[j] - ys[i], xs[j] - xs[i]));
            degree.push_back(atan2(ys[j] - ys[i], xs[j] - xs[i]) + 2 * pi);
        }
        sort(degree.begin(), degree.end());
        int ptr = 0;
        int res = INT_MAX;
        if (N == 1) res = 0;
        for (int j = 0; j < N - 1; ++j) {
            assert(ptr >= j);
            while (degree[ptr] - degree[j] <= pi - (1e-8)) ++ptr;            
            res = min(res, ptr - j - 1);
        }
        assert(res != INT_MAX);
        cout << res << endl;
    }
    return;
}

int MAIN() {    
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ":" << endl;
        solve();
    }
    return 0;
}

int main() {
    int start = clock();    
    ios :: sync_with_stdio(false);
    cout << fixed << setprecision(16);
    int ret = MAIN();
    #ifdef LOCAL
        cout << "[Finished in " << clock() - start << " ms]" << endl;
    #endif
    return ret;    
}
