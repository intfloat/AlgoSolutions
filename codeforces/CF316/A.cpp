#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int cand, city;
    scanf("%d %d", &cand, &city);
    vector<vector<int> > votes(city, vector<int>(cand));
    FOR(i, city) FOR(j, cand) {
        scanf("%d", &votes[i][j]);
    }
    int mx = -1, res = -1;
    map<int, int> cnt;
    FOR(i, city) {
        int t = *max_element(votes[i].begin(), votes[i].end());
        FOR(j, votes[i].size()) {
            if (votes[i][j] == t) {
                ++cnt[j];
                if (cnt[j] > mx || (cnt[j] == mx && j < res)) {
                    mx = cnt[j];
                    res = j;
                }
                break;
            }
        }
    }
    printf("%d\n", res + 1);
    return 0;
}
