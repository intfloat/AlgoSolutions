// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
typedef TreeNode* TreePtr;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tp = q.front();
            q.pop();
            if (tp == NULL) {
                ss << " null";
            }
            else {
                ss << " " << tp->val;
                q.push(tp->left);
                q.push(tp->right);
            }
        }
        string res, tmp;
        while (ss >> tmp) {
            res += " " + tmp;
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss;
        ss << data;
        string tmp;
        TreeNode* root = NULL;
        queue<TreePtr*> q;
        q.push(&root);
        while (ss >> tmp) {
            TreePtr* tp = q.front();
            q.pop();
            if (tmp == "null") {
                *tp = NULL;
                continue;
            }
            else {
                int val;
                stringstream st;
                st << tmp;
                st >> val;
                *tp = new TreeNode(val);
                q.push(&((*tp)->left));
                q.push(&((*tp)->right));
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
