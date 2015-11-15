#include <string>
#include <algorithm>
#include <map>
#include <deque>
#include <cassert>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

// this solution work in O(N) time complexity
class Solution {
public:
    string minWindow(string S, string T) {
        int slen = S.size();
        int tlen = T.size();
        // there is no valid window string
        if (tlen > slen) return "";
        int cs[200], ct[200];
        memset(cs, 0, sizeof(cs));
        memset(ct, 0, sizeof(ct));
        for (int i=0; i<tlen; i++) ct[T[i]]++;      
        int start = -1;
        int len = slen+1;
        deque<int> d;
        while(d.empty()==false) d.pop_front();
        int total = 0;
        for (int i=0; i<slen; i++) {
            if (ct[S[i]] == 0) continue;
            d.push_back(i);
            if (cs[S[i]] < ct[S[i]]) total++;
            cs[S[i]]++;             
            while (true) {
                char cur = S[d.front()];
                if (cs[cur] <= ct[cur]) break;
                else {
                    d.pop_front();
                    cs[cur]--;                  
                }
            }
            if (total>=tlen && d.back()-d.front()+1<len) {
                len = d.back() - d.front()+1;
                start = d.front();
            }
        }
        if (start < 0) return "";
        return S.substr(start, len);
    }
};
