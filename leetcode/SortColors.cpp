#include <algorithm>

using namespace std;

// use basic idea in quick sort
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int zero=0, two=n-1;
        for(int i=0; i<=two; i++){
            if(A[i] == 0){                
                swap(A[zero], A[i]);
                zero++;
            }
            else if(A[i] == 2){
                while(A[two]==2 && two>i)
                    two--;
                swap(A[two], A[i]);
                two--;                
                if(A[i] == 0)
                    i--;
            }            
        }// end for loop
        return;
    }
};
