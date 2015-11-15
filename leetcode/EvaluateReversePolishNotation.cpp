// EvaluateReversePolishNotation.cpp

#include <stack>

using namespace std;

class Solution {
public:

    // convert a string to integer
    // if in Java, we can just use Integer.parseInt()
    int convert(string s){
        int num = 0;
        for(int i=0; i<s.size(); i++){
            num = num*10+(s[i]-'0');
        }
        return num;
    }

    int evalRPN(vector<string> &tokens) {
         stack<int> s;
         int num1, num2;
         while(s.empty()==false) s.pop();
         for(int i=0; i<tokens.size(); i++){
            if(tokens[i].size()==1
                && (tokens[i][0]<'0' || tokens[i][0]>'9') ){
                num2 = s.top(); s.pop();
                num1 = s.top(); s.pop();
                if(tokens[i]=="+")
                    s.push(num1+num2);
                if(tokens[i]=="-")
                    s.push(num1-num2);
                if(tokens[i]=="*")
                    s.push(num1*num2);
                if(tokens[i]=="/")
                    // assume there won't be any arithmetic exception
                    s.push(num1/num2);
            }
            else{
                if(tokens[i][0]=='-')
                    s.push(-convert(tokens[i].substr(1, tokens[i].size()-1)));
                else s.push(convert(tokens[i]));
            }
         }// end for loop
         return s.top();
    }
};

