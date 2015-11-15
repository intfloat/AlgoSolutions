#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        res.clear();
        
        for(int i=0; i<(1<<n); i++){
            int cur = 0;
            cur = cur|((1<<(n-1))&i);
            for(int j=n-2; j>=0; j--)
                cur = cur | ((i&(1<<j))^((i>>1)&(1<<j)));
            res.push_back(cur);
        }
        
        return res;
    }
};
