#include <string>

using namespace std;

class Solution {
public:
    
  // convert integer to string, it will be much convenient in Java
    string convert(int number){
        string res = "";
        while(number != 0){
            char ch = number%10 + '0';
            res = ch + res;
            number = number/10;
        }
        return res;
    }
    
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string cur = "1";
        string result = "1";
        for(int i=2; i<=n; i++){
            int len = cur.size();
            result = "";
            int counter = 1;
            for(int j=1; j<len; j++){
                if(cur[j] == cur[j-1])
                    counter++;
                else{
                    result += convert(counter);
                    result += cur[j-1];
                    counter = 1;                    
                }
            }
            result += convert(counter);
            result += cur[len-1];
            cur = result;
        }// end for loop
        
        return result;
    }
};
