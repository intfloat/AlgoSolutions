#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int row, col;
    cin >> row >> col;
    vector<string> arr(row);
    FOR(i, row) cin >> arr[i];
    int res = 0;
    string s;
    for (int i = 0; i < row - 1; ++i) {
        for (int j = 0; j < col - 1; ++j) {
            s = arr[i].substr(j, 2);
            s += arr[i + 1].substr(j, 2);
            sort(s.begin(), s.end());
            res += (s == "acef");
        }
    }
    cout << res << endl;
    return 0;
}
