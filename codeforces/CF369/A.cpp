#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    cin >> n;
    vector<string> bus(n);
    FOR(i, n) {
        cin >> bus[i];
    }
    bool ok = false;
    FOR(i, n) {
        if (bus[i][0] == 'O' && bus[i][1] == 'O') {
            bus[i][0] = bus[i][1] = '+';
            ok = true;
            break;
        } else if (bus[i][3] == 'O' && bus[i][4] == 'O') {
            bus[i][3] = bus[i][4] = '+';
            ok = true;
            break;
        }
    }
    if (!ok) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        FOR(i, n) cout << bus[i] << endl;
    }
    return 0;
}
