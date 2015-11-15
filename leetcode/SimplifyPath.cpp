// SimplifyPath.cpp

#include <stack>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path = path + "/";
        stack<string> s;
        int len = path.size();
        string cur = "";
        for (int i = 0; i < len; i++) {
            if (path[i] == '/') {
                if (cur == "") continue;
                if (cur == ".") {
                    cur = "";
                    continue;
                }
                if (cur == "..") {                    
                    if (s.empty() == false) s.pop();
                }
                else s.push(cur);                
                cur = "";
            }
            else cur += path[i];
        }
        if (s.empty()) return "/";
        string res = "";
        while (s.empty() == false) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res;
    }
};
