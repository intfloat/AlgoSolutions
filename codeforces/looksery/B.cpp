#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int N, idx;
    cin >> N;
    vector<string> g(N);
    FOR(i, N) cin >> g[i];
    vector<int> pred(N);
    FOR(i, N) cin >> pred[i];
    vector<bool> selected(N, false);
    FOR(i, N) {
        bool zero = false;
        FOR(j, N) {
            if (pred[j] == 0) {
                zero = true;
                idx = j;
                break;
            }
        }
        if (zero) {
            selected[idx] = true;
            FOR(j, N) {
                if (g[idx][j] == '1') {
                    --pred[j];
                }
            }
            assert(pred[idx] != 0);
        } else {
            break;
        }
    }
    cout << accumulate(selected.begin(), selected.end(), 0) << endl;
    FOR(i, N) {
        if (selected[i]) cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}
