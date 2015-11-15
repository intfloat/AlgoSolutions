#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        result.push_back(num);
        while(next_permutation(num.begin(), num.end()) != false)
            result.push_back(num);
        return result;
    }
};
