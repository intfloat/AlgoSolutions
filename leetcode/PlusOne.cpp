#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = digits.size();
        stack<int> st;
        int carry = 0;
        digits[len-1]++;
        for(int i=len-1; i>=0; i--){
            st.push((carry+digits[i])%10);
            carry = (carry+digits[i])/10;           
        }
        if(carry!=0)
            st.push(carry);
        digits.clear();
        while(st.empty() == false){
            digits.push_back(st.top());
            st.pop();
        }
        return digits;
    }
};
