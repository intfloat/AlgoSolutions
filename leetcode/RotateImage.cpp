#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
          int N = matrix.size();
        // rotate 2D image in place
        for(int i=0; i<=(N-1)/2; i++)      
        for(int j=0; j<=(N-1)/2; j++){
            if(N%2==1 && i==(N-1)/2)
                break;
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[N-1-j][i];
            matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
            matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
            matrix[j][N-1-i] = tmp;
        }       
                
        return;
    }
};
