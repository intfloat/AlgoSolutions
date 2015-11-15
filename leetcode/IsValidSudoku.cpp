#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

    bool row[10][10], col[10][10], block[10][10];
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(block, false, sizeof(block));
        
        for(int i=0; i<9; i++)
        for(int j=0; j<9; j++){
            if(board[i][j]!='.'){
                int num = board[i][j]-'0';
                int blk = 3*(i/3)+j/3;
                if(row[i][num] || col[j][num] || block[blk][num])
                    return false;
                row[i][num]=true;
                col[j][num]=true;
                block[blk][num]=true;
            }
        }
        return true;
    }
};
