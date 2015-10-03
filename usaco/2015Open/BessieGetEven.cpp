#include <iostream>
#include <string>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const char cs[] = {'B', 'E', 'S', 'I', 'G', 'O', 'M'};
int main() {
    freopen("geteven.in", "r", stdin);
    freopen("geteven.out", "w", stdout);
    int N, number;
    char c;
    cin >> N;
    vector<vector<int> > cnt(26, vector<int>(2, 0));
    FOR(i, N) {
        cin >> c >> number;
        if (number % 2) ++cnt[c - 'A'][1];
        else ++cnt[c - 'A'][0];
    }
    int total = 1;
    FOR(i, 7) {
        int idx = cs[i] - 'A';
        total = total * (cnt[idx][0] + cnt[idx][1]);
    }
    int odd = cnt['M' - 'A'][1];
    odd *= cnt['B' - 'A'][1] * cnt['I' - 'A'][0] + cnt['B' - 'A'][0] * cnt['I' - 'A'][1];
    int val = 0;
    FOR(x1, 2) FOR(x2, 2) FOR(x3, 2) FOR(x4, 2) {
        // G O E S
        int t = x1 + x2 + x3 + x4;
        if (t % 2) val += cnt['G' - 'A'][x1] * cnt['O' - 'A'][x2] * cnt['E' - 'A'][x3] * cnt['S' - 'A'][x4];
    }
    odd *= val;
    cout << total - odd << endl;
    return 0;
}
