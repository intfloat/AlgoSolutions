class TrieNode {
public:
    TrieNode* nt[26];
    bool ok;
    TrieNode() {
        ok = false;
        for (int i = 0; i < 26; ++i) {
            nt[i] = NULL;
        }
    }
};
TrieNode* root;
void insert(const string& s) {
    TrieNode* cur = root;
    for (int i = 0; i < s.size(); ++i) {
        int val = s[i] - 'a';
        if (cur->nt[val] == NULL) {
            cur->nt[val] = new TrieNode();
        }
        cur = cur->nt[val];
    }
    cur->ok = true;
    return;
}

const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
class Solution {
public:
    int row, col;
    set<string> res;
    vector<vector<bool> > visited;
    vector<vector<char> > g;
    void dfs(int r, int c, TrieNode* ptr, const string& cur) {
        assert(ptr != NULL && r < row && r >= 0 && c >= 0 && c < col);
        if (ptr->ok) {
            res.insert(cur);
        }
        if (ptr->nt[g[r][c] - 'a'] == NULL) {
            return;
        }
        if (ptr->nt[g[r][c] - 'a']->ok) {
            res.insert(cur + g[r][c]);
        }
        visited[r][c] = true;
        int nr, nc;
        for (int i = 0; i < 4; ++i) {
            nr = r + dir_x[i];
            nc = c + dir_y[i];
            if (nr >= row || nr < 0 || nc >= col || nc < 0
                || visited[nr][nc]) {
                continue;
            }
            dfs(nr, nc, ptr->nt[g[r][c] - 'a'], cur + g[r][c]);
        }
        visited[r][c] = false;
        return;
    }
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        if (words.empty() || board.empty()) return vector<string>();
        row = board.size();
        col = board[0].size();
        g = board;
        visited.resize(row);
        for (int i = 0; i < row; ++i) {
            visited[i].resize(col);
            fill(visited[i].begin(), visited[i].end(), false);
        }
        root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            insert(words[i]);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                dfs(i, j, root, "");
            }
        }
        vector<string> ret;
        for (set<string>::iterator it = res.begin(); it != res.end(); ++it) {
            ret.push_back(*it);
        }
        return ret;
    }
};
