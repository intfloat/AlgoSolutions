#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      int dir_x[] = {0, 1, 0, -1};
        int dir_y[] = {1, 0, -1, 0};
        vector<vector<int> > matrix;
        vector<int> row;
        row.clear(); matrix.clear();
        for(int i=0; i<n; i++)
            row.push_back(0);
        for(int i=0; i<n; i++)
            matrix.push_back(row);
        int cur = 1;

        
        for(int i=0; i<(n+1)/2; i++){
            int x=i, y=i;
            for(int j=0; j<4; j++){
                for(int k=0; k<n-(2*i+1); k++){
                    matrix[x][y] = cur++;
                    x += dir_x[j];
                    y += dir_y[j];
                }
            }
        }
        if(n%2 == 1)
            matrix[(n-1)/2][(n-1)/2] = n*n;
        return matrix;
          
    }
};
