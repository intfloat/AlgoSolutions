// modified from cyg4ever
#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

void solve() {
    return;
}

int MAIN() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
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
