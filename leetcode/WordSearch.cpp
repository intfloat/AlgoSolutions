const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
class Solution {
public:
    int row, col, len;
    vector<vector<bool> > visited;
    bool res;
    string w;   
    vector<vector<char> > graph;
    bool exist(vector<vector<char> > &board, string word) {
        graph = board;
        res = false;
        w = word;
        row = board.size();
        col = board[0].size();
        len = word.size();
        visited.resize(row);
        for (int i = 0; i < row; ++i) {
            visited[i].resize(col);
            fill(visited[i].begin(), visited[i].end(), false);
        }        
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (word[0] == board[i][j]) dfs(i, j, 0);
                if (res) return true;
            }
        }
        return res;
    }

    void dfs(int r, int c, int pos) {
        if (pos == len || res) {
            res = true;
            return;
        }       
        if (w[pos] != graph[r][c]) return;
        if (pos == len - 1) {
            res = true;
            return;
        }
        visited[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int x = dir_x[i] + r;
            int y = dir_y[i] + c;
            if(x < 0 || x >= row || y < 0 || y >= col || visited[x][y]) continue;
            dfs(x, y, pos + 1);
            if(res) return;
        }
        visited[r][c] = false;
        return;
    }
};

