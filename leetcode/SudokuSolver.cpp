#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    // I think simple dfs will work.
    bool row[9][10], col[9][10], group[3][3][10];
    bool ok;
    vector<vector<char> > g;    

    void dfs(int r, int c) {
        if (r == 9) {
            ok = true;
            return;
        }
        if (ok) return;
        int nc = (c+1)%9;
        int nr = r;
        // enter another new row
        if (c == 8) nr++;
        if (g[r][c] != '.') {
            dfs(nr, nc);
        }
        else {
            for (int i=1; i<=9; i++) {
                if (row[r][i] || col[c][i]) continue;
                if (group[r/3][c/3][i]) continue;
                g[r][c] = '0'+i;
                row[r][i] = true;
                col[c][i] = true;
                group[r/3][c/3][i] = true;
                dfs(nr, nc);
                if (ok) return;
                row[r][i] = false;
                col[c][i] = false;
                group[r/3][c/3][i] = false;
                g[r][c] = '.';
            }
        }
        return;
    }

    void solveSudoku(vector<vector<char> > &board) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(group, false, sizeof(group));
        g = board; 
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (g[i][j] != '.') {
                    int number = g[i][j] - '0';
                    row[i][number] = true;
                    col[j][number] = true;
                    group[i/3][j/3][number] = true;
                }
            }
        }
        ok = false;
        dfs(0, 0);
        // this step of copying object is important
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                board[i][j] = g[i][j];
            }
        }
        return;
    }
};
