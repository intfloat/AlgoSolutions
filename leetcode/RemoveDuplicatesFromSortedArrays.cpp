class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(n==0)
            return 0;
        
        int ptr1=1, ptr2=1;
        while(ptr2 != n){
            if(A[ptr2] == A[ptr2-1])
                ptr2++;
            else
                A[ptr1++] = A[ptr2++];
        }
        return ptr1;
    }
};
