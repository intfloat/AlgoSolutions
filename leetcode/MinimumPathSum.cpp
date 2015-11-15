#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = grid.size();
        int col = grid[0].size();
        long long dp[row][col];
        
        dp[0][0] = grid[0][0];
        for(int i=1; i<col; i++)
            dp[0][i] = dp[0][i-1]+grid[0][i];
        for(int i=1; i<row; i++)
            dp[i][0] = dp[i-1][0]+grid[i][0];
        for(int i=1; i<row; i++)
        for(int j=1; j<col; j++)
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
        return dp[row-1][col-1];
    }
};
