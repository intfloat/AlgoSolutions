#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        
        map<string, int> m;
        for(int i=0; i<strs.size(); i++){
        // sort the string 
            string s = strs[i];
            sort(s.begin(), s.end());
            if(m.find(s) == m.end()){
                m[s] = i;
            }
            else{
                // push back the previous occured string
                if(m[s] >= 0){
                    result.push_back(strs[m[s]]);
                    m[s] = -1;
                }
                result.push_back(strs[i]);
            }
        }// end for loop
        
        return result;
    }
};
