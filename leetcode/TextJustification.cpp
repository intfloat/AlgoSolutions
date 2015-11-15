#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = words.size();
        vector<string> res;
        res.clear();
        string cur = "";
        
        for(int i=0; i<len; i++){
            int left=i, right=i;
            int counter = words[left].size();
            for(int j=left+1;j<len; j++){
                counter += 1+words[j].size();
                if(counter > L){
                    right = j-1;
                    counter -= 1+words[j].size();
                    break;
                }
                if(j==len-1 && counter<=L){
                    right = len-1;
                    break;
                }
            }
            if(right == len-1){
                cur = words[left];
                for(int j=left+1; j<=right; j++)
                    cur += " "+words[j];
                for(int j=0; j<L-counter; j++)
                    cur += " ";
                res.push_back(cur);
                return res;
            }
            else if(right == left){
                cur = words[left];
                for(int j=0; j<L-words[left].size(); j++)
                    cur += " ";
                res.push_back(cur);
                i = right;
            }
            else{
                int space = right-left;
                int mod = (L-counter+space)%space;
                int num = (L-counter+space)/space;
                cur = words[left];
                for(int j=left+1; j<=right; j++){
                    for(int k=0; k<num; k++)
                        cur += " ";
                    if(j-left <= mod)
                        cur += " ";
                    cur += words[j];
                }
                res.push_back(cur);
                i=right;
            }
        }// end for loop
        return res;
    }
};
