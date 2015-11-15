#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        int col = matrix[0].size();
        bool firstRow = false;
        bool firstCol = false;
        
        for(int i=0; i<col; i++)
            firstRow = firstRow || (matrix[0][i]==0);
        for(int i=0; i<row; i++)
            firstCol = firstCol || (matrix[i][0]==0);
        for(int i=1; i<row; i++)
        for(int j=1; j<col; j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
                
        for(int i=1; i<row; i++)
        for(int j=1; j<col; j++){
            if(matrix[i][0]==0 || matrix[0][j]==0)
                matrix[i][j]=0;
        }
        
        if(firstRow==true){
            for(int i=0; i<col; i++)
                matrix[0][i]=0;
        }
        if(firstCol==true){
            for(int i=0; i<row; i++)
                matrix[i][0]=0;
        }
        return;
    }
};
