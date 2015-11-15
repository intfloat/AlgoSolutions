#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        while(s.empty()==false) s.pop();
        int len = height.size();
        int res = 0;
        for (int i=0; i<len; i++) {
            if (s.empty() || height[i]>height[s.top()])
                s.push(i);
            else {
                while (s.empty()==false && height[i]<=height[s.top()]) {
                    int index = s.top();
                    s.pop();
                    int left = 0;
                    if (s.empty() == false) left = s.top()+1;
                    res = max(res, height[index]*(i-left));
                }
                s.push(i);
            }
        }
        while (s.empty() == false) {
            int cur = s.top();
            s.pop();
            int left = 0;
            if (s.empty() == false) left = s.top()+1;
            res = max(res, height[cur]*(len-1-left+1));
        }
        return res;
    }
};
