#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val = 0;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int> > levelOrder(Node* root) {
        vector<vector<int> > res;
        queue<pair<Node*, int> > q;
        q.push({root, 0});
        while (!q.empty()) {
            pair<Node*, int> tp = q.front();
            q.pop();
            if (NULL == tp.first) {
                continue;
            }
            int idx = tp.second;
            if (idx == res.size()) {
                res.push_back(vector<int>());
            }
            Node* ptr = tp.first;
            res[idx].push_back(ptr->val);
            for (int i = 0; i < ptr->children.size(); ++i) {
                q.push({ptr->children[i], idx + 1});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}