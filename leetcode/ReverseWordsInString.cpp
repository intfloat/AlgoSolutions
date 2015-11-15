// ReverseWordsInString.cpp

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // works in linear time
    void reverseWords(string &s) {
        string t = "";
        int len = s.size();
        int fir = 0;
        int last = len-1;
        while(fir<len && s[fir]==' ') fir++;
        while(last>=0 && s[last]==' ') last--;
        if(fir>=len || last<0){
            s = t;
            return;
        }
        for(int i=fir; i<=last; i++){
            if(s[i]==' '&&s[i-1]==' ') continue;
            t += s[i];
        }
        reverse(t.begin(), t.end());
        len = t.size();
        last = len-1; fir = len-1;
        while(fir>=0){
            while(fir>=0 && t[fir]!=' ') fir--;
            reverse(t.begin()+fir+1, t.begin()+last+1);
            fir--;
            last = fir;
        }
        s = t;
        return;
    }
};
