#include <string>
#include <stack>

using namespace std;

// simulate the whole process is ok.
class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
          int len1 = a.size();
    int len2 = b.size();
        int ptr1=len1-1, ptr2=len2-1;
        int carry = 0;
        stack<int> res;
        
        while(true){
            // addition process has ended
            if(ptr1<0 && ptr2<0 && carry>0){
                res.push(carry);
                break;
            }
            // no carry
            else if(ptr1<0 && ptr2<0 && carry==0)
                break;
            // two numbers to add
            else if(ptr1>=0 && ptr2>=0){
                res.push(((a[ptr1]-'0')+(b[ptr2]-'0')+carry)%2);
                carry = ((a[ptr1]-'0')+(b[ptr2]-'0')+carry)/2;
            }
            // only one number to add
            else if(ptr1<0 && ptr2>=0){
                res.push((b[ptr2]-'0'+carry)%2);
                carry = (carry + b[ptr2]-'0')/2;
            }
            // only one number to add
            else if(ptr1>=0 && ptr2<0){
                res.push((a[ptr1]-'0'+carry)%2);
                carry = (carry + a[ptr1]- '0')/2;
            }
            // move pointer
            ptr1--; ptr2--;
        }
        
        // get result from a stack
        string s = "";
        while(res.empty()==false){
            char tmp = res.top()+'0';
            res.pop();
            s = s+tmp;
        }
        return s;
    }
};
