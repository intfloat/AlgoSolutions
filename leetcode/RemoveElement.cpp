class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(n==0)
            return 0;
        
        int ptr = 0;
        for(int i=0; i<n; i++){
            if(elem != A[i]){
                A[ptr++] = A[i];                
            }
        }
        return ptr;
        
    }
};
