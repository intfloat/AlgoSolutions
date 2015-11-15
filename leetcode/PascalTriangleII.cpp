#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        res.clear();
        vector<int> record;
        
        
        for(int i=0; i<=rowIndex; i++){
            record.clear();
            for(int j=0; j<=i; j++){
                if(j==0)
                    record.push_back(1);
                else if(j==i)
                    record.push_back(1);
                else
                    record.push_back(res[j-1]+res[j]);
            }
            res = record;
        }
        
        return res;      
    }
};
