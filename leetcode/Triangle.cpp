#include <vector>
#inlude <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = triangle.size();
        int col = triangle[row-1].size();
        
        for(int i=row-2; i>=0; i--){
            for(int j=0; j<i+1; j++)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
        
        return triangle[0][0];
    }
};
