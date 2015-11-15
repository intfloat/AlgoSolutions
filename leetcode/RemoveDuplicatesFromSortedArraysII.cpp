class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(n <= 2)
            return n;
        
        int ptr=1;
        bool flag = false;
        
        for(int i=1; i<n; i++){
            // first time duplicate occur
            if(A[i]==A[i-1] && flag==false){
                flag=true;
                A[ptr++] = A[i];
            }
            else if(A[i]!=A[i-1]){
                flag = false;
                A[ptr++] = A[i];
            }
            // duplicate occur more than 2 times
            else if(A[i]==A[i-1] && flag==true)
                continue;           
        }
        return ptr;
    }
};
