// WordLadder.cpp

#include <queue>
#include <utility>
#include <string>

using namespace std;

class Solution {
public:
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string>::iterator it;
        queue<pair<string, int> > q;
        int len = start.size();     
        while(q.empty()==false) q.pop();
        q.push(make_pair(start, 1));
        it = dict.find(start);
        if(it!=dict.end()) dict.erase(it);
        while(q.empty()==false){
            pair<string, int> top = q.front();
            q.pop();
            for(int i=0; i<len; i++){
                for(char cur='a'; cur<='z'; cur++){
                    if(cur==top.first[i]) continue;
                    string t = top.first;
                    t[i] = cur;
                    it = dict.find(t);
                    if(it==dict.end()) continue;
                    if(t==end) return top.second+1;
                    q.push(make_pair(t, top.second+1));
                    dict.erase(it);
                }
            }
        }
        return 0;
    }
};
