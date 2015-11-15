#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n-1;
        vector<int> result;        
        
        // search for the left boundary
        while(left < right){
        int middle = (left+right)>>1;
            if(A[middle] == target)
                right = middle;
            else if(A[middle] < target)
                left = middle+1;
            else
                right = middle-1;               
        }
        if(A[left] != target){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        
        
        // search for the right most boundary
        result.push_back(left);
        left=0; right=n-1;
        while(left+1 < right){
            int mid = (left+right)>>1;
            if(A[mid] == target)
                left = mid;
            else if(A[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        if(A[right]==target)
            result.push_back(right);
        else
            result.push_back(left);
        return result;
    }
};
