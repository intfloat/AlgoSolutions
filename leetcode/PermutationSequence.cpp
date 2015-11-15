#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int fact[12];
        fact[0] = 1;
        for(int i=1; i<=10; i++)
            fact[i] = fact[i-1]*i;
        vector<int> number;
        number.clear();
        for(int i=1; i<=n; i++)
            number.push_back(i);
        
        string res = "";
        for(int i=1; i<=n; i++){
            int unit = fact[n-i];
            for(int j=1; j<=n+1-i; j++){
                if(k <= unit*j){
                    res += (char)(number[j-1]+'0');
                    k -= unit*(j-1);
                    number.erase(number.begin()+(j-1));
                    break;
                }
            }
        }// end for loop
        return res;
    }
};
