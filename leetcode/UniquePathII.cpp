#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
          int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
        long long dp[105][105];
        for(int i=0; i<row; i++){
            if(obstacleGrid[i][0]==1)
                dp[i][0]=0;
            else if(i==0)
                dp[i][0]=1;
            else
                dp[i][0]= dp[i-1][0];
        }
        for(int i=0; i<col; i++){
            if(obstacleGrid[0][i]==1)
                dp[0][i]=0;
            else if(i==0)
                dp[0][i]=1;
            else
                dp[0][i] = dp[0][i-1];
        }
        
        // dynamic programming
        for(int i=1; i<row; i++)
        for(int j=1; j<col; j++){
            if(obstacleGrid[i][j]==1)
                dp[i][j]=0;
            else
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
        }// end for loop
        
        return dp[row-1][col-1];
    }
};
