#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int main() {
    vector<vector<int> > arr;
    vector<int> res;
    int N, pos, val, cnt;
    while (scanf("%d", &N) != EOF) {
        arr.resize(N);
        FOR(i, N) arr[i].clear();
        FOR(i, N) {
            scanf("%d", &cnt);
            FOR(j, cnt) {
                scanf("%d", &val);
                arr[i].push_back(val);
            }
        }
        FOR(i, N) sort(arr[i].begin(), arr[i].end(), greater<int>());
        res.clear();
        FOR(i, N) {
            FOR(j, arr[i].size()) {
                pos = lower_bound(res.begin(), res.end(), arr[i][j]) - res.begin();
                if (pos == res.size()) res.push_back(arr[i][j]);
                else res[pos] = arr[i][j];
            }
        }
        printf("%d\n", res.size());
    }
    return 0;
}
