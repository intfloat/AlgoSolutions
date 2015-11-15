#include <vector>
#include <string>

using namespace std;

// just simulate the whole process
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        vector<char> v[5000];
        for(int i=0; i<nRows; i++)
            v[i].clear();
        int ptr = 0;
        int len = s.size();
        while(ptr < len){
            for(int i=0; i<nRows && ptr<len; i++){
                v[i].push_back(s[ptr++]);
            }
            for(int i=nRows-2; i>=1 && ptr<len; i--){
                for(int j=0; j<nRows; j++){
                    if(i == j)
                        v[j].push_back(s[ptr++]);
                    else v[j].push_back(' ');
                }
            }// end for loop
        }// end while loop
        
        string res = "";
        for(int i=0; i<nRows; i++)
        for(vector<char>::iterator it=v[i].begin(); it!=v[i].end(); it++){
            if((*it) != ' ')
                res += (*it);
        }
        
        return res;
    }
};
