#include <cstring>

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        
        for(int i=0; i<=len1-len2; i++){
            bool ok = true;
            for(int j=i; j<i+len2; j++){
                if(haystack[j] != needle[j-i]){
                    ok = false;
                    break;
                }
            }
            if(ok == true)
                return haystack+i;
        }
        return NULL;
    }
};
