#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> res;
  int paren;
    
    void dfs(string cur, int left, int right){
        if(right == paren){
            res.push_back(cur);
            return;
        }
        if(left == paren)
            dfs(cur+")", left, right+1);
        else if(left == right)
            dfs(cur+"(", left+1, right);        
        else{
            dfs(cur+"(", left+1, right);
            dfs(cur+")", left, right+1);
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        paren = n;
        string cur = "";
        dfs(cur, 0, 0);
        return res;
    }
};
