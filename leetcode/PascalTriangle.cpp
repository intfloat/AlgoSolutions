#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        res.clear();
        vector<int> record;
          
        if(numRows == 0)
            return res;
        
        for(int i=0; i<numRows; i++){
            record.clear();
            for(int j=0; j<=i; j++){
                if(j==0)
                    record.push_back(1);
                else if(j==i)
                    record.push_back(1);
                else
                    record.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            res.push_back(record);
        }
        
        return res;
    }
};
