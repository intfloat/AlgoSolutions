#include <stack>
#include <algorithm>
#include <string>

using namespace std;


// I think it is a dynamic programming problem
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        stack<pair<char, int> > st;
        while(st.empty() == false)
            st.pop();
        int result = 0, cur = 0;
        int len = s.size();
        for(int i=0; i<len; i++){
        if(s[i]=='(')
                st.push(make_pair(s[i], i));
            else if(s[i]==')' && st.empty()==false){
                cur++;
                //result = max(result, cur);
                st.pop();
                if(st.empty() == true)
                    result = max(result, cur);
            }
            else if(s[i]==')' && st.empty()==true){
                cur = 0;
                while(st.empty()==false)
                    st.pop();
            }
        }// end for loop
        while(st.empty() == false){
            pair<char, int> tmp = st.top();
            st.pop();
            result = max(result, (len-tmp.second-1)/2);
            len = tmp.second;
        }
        return result*2;
    }
};
