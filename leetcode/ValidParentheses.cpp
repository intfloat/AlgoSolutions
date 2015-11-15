#include <iostream>

using namespace std;


// I think we can use stack to solve this problem
class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        stack<char> st;
        bool valid = true;
        for(int i=0; i<len; i++){
        if(st.empty() == true){
                if(s[i]=='}' || s[i]==']' || s[i]==')'){
                    valid = false;
                    break;
                }
                st.push(s[i]);
            }// end if clause
            
            else{
                char pre = st.top();
                if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                    st.push(s[i]);
                else if(pre=='{' && s[i]=='}')
                    st.pop();
                else if(pre=='(' && s[i]==')')
                    st.pop();
                else if(pre=='[' && s[i]==']')
                    st.pop();
                else{
                    valid = false;
                    break;
                }
            }// end else clause
        }// end for loop
        
        if(st.empty() == false)
            valid = false;
        
        return valid;       
    }// end method isValid
};
