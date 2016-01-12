#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    vector<vector<int> > arr(row, vector<int>(col));
    FOR(i, row) FOR(j, col) scanf("%d", &arr[i][j]);
    vector<int> res;
    FOR(i, row) res.push_back(*min_element(arr[i].begin(), arr[i].end()));
    printf("%d\n", *max_element(res.begin(), res.end()));
    return 0;
}
