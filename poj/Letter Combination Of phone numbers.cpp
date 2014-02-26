#include <vector>
#include <string>
using namespace std;

string str[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    vector<string> res;
	string d;
	
	int len;
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  		len = digits.size();  		
  		d = digits;
		//if(len == 0) 
		//	return res;
		string cur = "";
        res.clear();
		dfs(cur, 0);
		return res;
    }
    
    // use depth first search to construct result
    void dfs(string cur, int ptr){
		if(ptr == len){
			res.push_back(cur);
			return;
		}
		int num = d[ptr]-'0';
		for(int i=0; i<str[num].size(); i++)
			dfs(cur+str[num][i], ptr+1);
		return;
	}
};
