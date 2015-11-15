
// I think binary search can be used to solve this problem
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long left=0, right=x;
        while(left <= right){
        long long mid = (left+right)>>1;
            if(mid*mid == x)
                return mid;
            else if(mid*mid < x)
                left = mid+1;
            else
                right = mid-1;
        }
        return right;
    }
};
