/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> st;
        vector<int> res;
        if (NULL == root) {
            return res;
        }
        st.push(root);
        while (!st.empty()) {
            Node* tp = st.top();
            st.pop();
            if (NULL == tp) continue;
            res.push_back(tp->val);
            for (int i = 0; i < tp->children.size(); ++i) {
                st.push(tp->children[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;

    }
};