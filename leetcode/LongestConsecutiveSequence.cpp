#include <vector>
#include <algorithm>

using namespace std;

// O(nlgn) complexity, but I think it is simpler than using hash map
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 1;        
        int cur = 1;
        sort(num.begin(), num.end());       
        unique(num.begin(), num.end());
        int len = num.size();
        if(len <= 1)
            return len;
            
        for(int i=1; i<len; i++){
            if(num[i] == num[i-1]+1)
                cur++;
            else
                cur = 1;
            res = max(res, cur);
        }
        
        return res;
    }
};
