#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (int)n; ++i)

const int dir_x[] = {2, 2, 1, 1, -2, -2, -1, -1};
const int dir_y[] = {1, -1, 2, -2, 1, -1, 2, -2};

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double> > cur_p(N, vector<double>(N, 0.0));
        vector<vector<double> > new_p(N, vector<double>(N, 0.0));
        cur_p[r][c] = 1.0;
        FOR(step, K) {
            FOR(i, N) FOR(j, N) new_p[i][j] = 0.0;
            FOR(rr, N) FOR(cc, N) FOR(i, 8) {
                int nr = dir_x[i] + rr;
                int nc = dir_y[i] + cc;
                if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    new_p[nr][nc] += 1.0 / 8 * cur_p[rr][cc];
                }
            }
            cur_p = new_p;
        }

        double res = 0;
        FOR(i, N) FOR(j, N) res += cur_p[i][j];
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.knightProbability(3, 2, 0, 0) << endl;
    return 0;
}
