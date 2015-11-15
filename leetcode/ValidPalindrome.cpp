#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string t = "";
        int len = s.size();
        for(int i=0; i<len; i++){
            if(s[i]>='a' && s[i]<='z')
                t += s[i];
            else if(s[i]>='A' && s[i]<='Z')
                t += (s[i]+32);
            else if(s[i]>='0' && s[i]<='9')
                t += s[i];
        }
        len = t.size();
        for(int i=0; i<len/2; i++){
            if(t[i] != t[len-i-1])
                return false;
        }
        return true;
    }
};
