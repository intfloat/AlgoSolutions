#include <vector>
#include <queue>
#include <string.h>

using namespace std;


class Solution {
public:
    int row, col;
    vector<vector<char> > b;
    bool flag[500][500];    
    
    void bfs(int r, int c){
        int dir_x[] = {0, 0, 1, -1};
        int dir_y[] = {-1, 1, 0, 0};
        queue<pair<int, int> > q;
        while(q.empty() == false)
            q.pop();
        q.push(make_pair(r, c));
        flag[r][c] = false;
        while(q.empty() == false){
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int x = p.first+dir_x[i];
                int y = p.second+dir_y[i];
                if(x>=row || x<0 || y>=col || y<0)
                    continue;
                if(b[x][y]=='X' || flag[x][y]==false)
                    continue;
                flag[x][y] = false;
                q.push(make_pair(x, y));
            }
        }
        return;
    }
    
    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        row = board.size();
          
        if(row == 0)
            return;
            
        col = board[0].size();
        b = board;
        memset(flag, true, sizeof(flag));
        
        for(int i=0; i<col; i++){       
            if(board[0][i]=='O' && flag[0][i]==true)
                bfs(0, i);
            if(board[row-1][i]=='O' && flag[row-1][i]==true)
                bfs(row-1, i);
        }
        for(int i=0; i<row; i++){
            if(board[i][0]=='O' && flag[i][0]==true)
                bfs(i, 0);
            if(board[i][col-1]=='O' && flag[i][col-1]==true)
                bfs(i, col-1);
        }
        
        for(int i=0; i<row; i++)
        for(int j=0; j<col; j++){
            if(flag[i][j]==true)
                board[i][j] = 'X';
        }
        
        return;
    }
};
