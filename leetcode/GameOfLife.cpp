const int dir_x[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dir_y[] = {1, -1, 0, 0, 1, -1, 1, -1};
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int nr = i + dir_x[k], nc = j + dir_y[k];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
                    cnt += ((board[nr][nc] & 1) > 0);
                }
                bool live = ((board[i][j] & 1) > 0);
                if (live && (cnt < 2 || cnt > 3)) continue;
                else if (live) board[i][j] += 2;
                else if (!live && cnt == 3) board[i][j] += 2;
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                board[i][j] >>= 1;
            }
        }
        return;
    }
};
