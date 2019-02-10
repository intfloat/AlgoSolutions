#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

/*
// Definition for a QuadTree node.
*/
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
private:
    void solve(Node* root, Node* t1, Node* t2) {
        if ((t1->isLeaf && t1->val) || (t2->isLeaf && t2->val)) {
            root->isLeaf = true;
            root->val = true;
            root->topLeft = root->topRight = root->bottomLeft = root->bottomRight = NULL;
            return;
        }
        if (t1->isLeaf && !t1->val) {
            root->isLeaf = t2->isLeaf;
            root->val = t2->val;
            root->topLeft = t2->topLeft;
            root->topRight = t2->topRight;
            root->bottomLeft = t2->bottomLeft;
            root->bottomRight = t2->bottomRight;
            return;
        }
        if (t2->isLeaf && !t2->val) {
            root->isLeaf = t1->isLeaf;
            root->val = t1->val;
            root->topLeft = t1->topLeft;
            root->topRight = t1->topRight;
            root->bottomLeft = t1->bottomLeft;
            root->bottomRight = t1->bottomRight;
            return;
        }

        root->isLeaf = false;
        root->val = false;
        root->topLeft = new Node();
        solve(root->topLeft, t1->topLeft, t2->topLeft);
        root->topRight = new Node();
        solve(root->topRight, t1->topRight, t2->topRight);
        root->bottomLeft = new Node();
        solve(root->bottomLeft, t1->bottomLeft, t2->bottomLeft);
        root->bottomRight = new Node();
        solve(root->bottomRight, t1->bottomRight, t2->bottomRight);

        if (root->topLeft->isLeaf && root->topLeft->val && root->topRight->val && root->bottomLeft->val && root->bottomRight->val) {
            root->isLeaf = true;
            root->val = true;
            root->topLeft = root->topRight = root->bottomLeft = root->bottomRight = NULL;
        } else if (root->topLeft->isLeaf && !root->topLeft->val && !root->topRight->val && !root->bottomLeft->val && !root->bottomRight->val) {
            root->isLeaf = true;
            root->val = false;
            root->topLeft = root->topRight = root->bottomLeft = root->bottomRight = NULL;
        }
    }
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1 == NULL || quadTree2 == NULL) {
            return NULL;
        }
        Node* root = new Node();
        solve(root, quadTree1, quadTree2);
        return root;
    }
};

int main() {
    Solution solution;
    return 0;
}

