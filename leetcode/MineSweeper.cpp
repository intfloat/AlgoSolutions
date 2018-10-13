#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int dir_x[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dir_y[] = {-1, 1, -1, 0, 1, -1, 0, 1};
int get_cnt(const vector<vector<char>>& board, const int x, const int y) {
    int ret = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        if (nx < 0 || nx >= (int)board.size() || ny < 0 || ny >= (int)board[0].size()) {
            continue;
        }
        ret += (board[nx][ny] == 'X' || board[nx][ny] == 'M');
    }
    return ret;
}

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        queue<pii> q;
        int cnt = get_cnt(board, x, y);
        board[x][y] = cnt > 0 ? '0' + cnt : 'B';
        if (cnt == 0) {
            q.push({x, y});
        }
        while (!q.empty()) {
            pii tp = q.front();
            q.pop();
            for (int i = 0; i < 8; ++i) {
                int nx = tp.first + dir_x[i];
                int ny = tp.second + dir_y[i];
                if (nx < 0 || nx >= (int)board.size() || ny < 0 || ny >= (int)board[0].size()) {
                    continue;
                }
                if (board[nx][ny] == 'E') {
                    int c = get_cnt(board, nx, ny);
                    board[nx][ny] = c > 0 ? '0' + c : 'B';
                    if (c == 0) {
                        q.push({nx, ny});
                    }
                }
            }
        }
        return board;
    }
};

int main() {
    Solution sol;
    return 0;
}