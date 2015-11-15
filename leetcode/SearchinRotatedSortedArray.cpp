class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n-1;
        // find last element larger than A[0]      
        while(left+1 < right){         
            int middle = (left+right)>>1;
            if(A[middle] > A[0])
                left = middle;
            else
                right = middle-1;
        }
        
        if(A[right] > A[left])
            left = right;
        
        // set the range for binary search
        int l, r;
        if(target >= A[0]){
            l=0; r=left;
        }
        else{
            l=left+1; r=n-1;
        }
        
        // binary search
        while(l <= r){
            int mid = (l+r)>>1;
            if(A[mid] == target)
                return mid;
            else if(A[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        return -1;
    }
};
