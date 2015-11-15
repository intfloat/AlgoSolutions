#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //next_permutation(num.begin(), num.end());
        //return;
        
        int len = num.size();
        for(int i=len-1; i>0; i--){
            if(num[i] > num[i-1]){              
                int pos;
                for(int j=len-1; j>=i; j--){
                    if(num[j] > num[i-1]){
                        pos = j;
                        break;
                    }
                }
                swap(num[pos], num[i-1]);
                sort(num.begin()+i, num.end());
                return;
            }
        }// end for loop
        
        // it is already in descending order
        sort(num.begin(), num.end());
        return;
    }
};
