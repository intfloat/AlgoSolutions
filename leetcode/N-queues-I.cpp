#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  int flag[20][20];
    int row;
    vector<vector<string> > res;
    vector<string> board;
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function         
        string tmp = "";
        row = n;
        res.clear(); board.clear();
        for(int i=0; i<n; i++)
            tmp += ".";
        for(int i=0; i<n; i++)
            board.push_back(tmp);       
        memset(flag, 0, sizeof(flag));
        
        dfs(0);
        
        return res;
    }
    
    void dfs(int step){
        if(step==row){
            res.push_back(board);
            return;
        }
        for(int i=0; i<row; i++){
            if(flag[step][i]==0){
                board[step][i] = 'Q';
                for(int j=step+1; j<row; j++){
                    flag[j][i]++;
                    if(j-step+i < row)
                        flag[j][j-step+i]++;
                    if(i-j+step >= 0)
                        flag[j][i-j+step]++;
                }
                dfs(step+1);
                
                board[step][i]='.';
                for(int j=step+1; j<row; j++){
                    flag[j][i]--;
                    if(j-step+i < row)
                        flag[j][j-step+i]--;
                    if(i-j+step >= 0)
                        flag[j][i-j+step]--;
                }
            }// end if 
        }// end for loop
    }// end function dfs
};
