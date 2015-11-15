class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(n==0)
            return;
        if(m==0){
        for(int i=0; i<n; i++)
                A[i] = B[i];
            return;
        }
        
        int *tmp = new int[m];
        for(int i=0; i<m; i++)
            tmp[i] = A[i];
        int ptr = 0;
        int ptr1=0, ptr2=0;
        while(ptr1<m && ptr2<n){
            if(tmp[ptr1] < B[ptr2])
                A[ptr++] = tmp[ptr1++];
            else
                A[ptr++] = B[ptr2++];
        }
        while(ptr1 < m)
            A[ptr++] = tmp[ptr1++];
        while(ptr2 < n)
            A[ptr++] = B[ptr2++];
        return;
    }
};
