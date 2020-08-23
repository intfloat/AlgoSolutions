#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

int dir_x[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dir_y[] = {1, -1, -1, 0, 1, -1, 0, 1};
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res = M;
        int row = M.size(), col = M[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int sum = M[i][j];
                int cnt = 1;
                for (int d = 0; d < 8; ++d) {
                    int nx = i + dir_x[d];
                    int ny = j + dir_y[d];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                        sum += M[nx][ny];
                        ++cnt;
                    }
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}
