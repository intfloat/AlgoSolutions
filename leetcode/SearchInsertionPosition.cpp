
// search for the first position that is no less than target value
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // this is a special case
        if(target > A[n-1])
            return n;
          
        int left = 0, right = n-1;
        while(left < right){
            int mid = (left+right)>>1;
            if(A[mid] == target)
                return mid;
            else if(A[mid] < target)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};
