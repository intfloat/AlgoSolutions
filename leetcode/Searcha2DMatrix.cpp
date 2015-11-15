#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = row*col-1;
        
        while(left <= right){
            int mid = (left+right)>>1;
            int x = mid/col;
            int y = mid%col;
            if(matrix[x][y]==target)
                return true;
            else if(matrix[x][y] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return false;
    }
};
