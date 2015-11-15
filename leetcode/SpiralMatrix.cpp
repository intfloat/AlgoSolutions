#include <vector>

using namespace std;


const int dir_x[] = {0, 1, 0, -1};
const int dir_y[] = {1, 0, -1, 0};      

class Solution {
public: 
    vector<vector<int> >  m;
    vector<int> res;
    int N, M;
    
    void visit(int x, int y, int row, int col){
        if(row==0 || col==0)
            return;
        if(row == 1){
            for(int i=0; i<col; i++)
                res.push_back(m[x][y+i]);
            return;
        }
        if(col == 1){
            for(int i=0; i<row; i++)
                res.push_back(m[x+i][y]);
            return;
        }
        
        int xx=x, yy=y;
        for(int i=0; i<4; i++){
            int len;
            if(i%2 == 0)
                len = col-1;
            else
                len = row-1;
            for(int j=0; j<len; j++){
                res.push_back(m[xx][yy]);
                xx += dir_x[i];
                yy += dir_y[i];
            }
        }
        visit(x+1, y+1, row-2, col-2);
    }
    
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function     
        res.clear();
        N= matrix.size();
        if(N == 0)
            return res;
        M = matrix[0].size();
        m = matrix;
        
        visit(0, 0, N, M);
                
        return res;
    }
};
