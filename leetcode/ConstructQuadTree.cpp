#include <bits/stdc++.h>
using namespace std;

// Definition for a QuadTree node.
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
    bool check(vector<vector<int> >& grid, const int r, const int c, const int h, const int w) {
        bool has_true = false, has_false = false;
        for (int i = r; i < r + h; ++i) {
            for (int j = c; j < c + w; ++j) {
                if (has_true && has_false) {
                    return false;
                }
                has_true = has_true || grid[i][j];
                has_false = has_false || !grid[i][j];
            }
        }
        return true;
    }
    Node* solve(vector<vector<int> >& grid, const int r, const int c, const int h, const int w) {
        if (check(grid, r, c, h, w)) {
            return new Node((bool)grid[r][c], true, NULL, NULL, NULL, NULL);
        } else {
            Node* root = new Node();
            root->isLeaf = false;
            root->topLeft = solve(grid, r, c, h >> 1, w >> 1);
            root->topRight = solve(grid, r, c + (w >> 1), h >> 1, w >> 1);
            root->bottomLeft = solve(grid, r + (h >> 1), c, h >> 1, w >> 1);
            root->bottomRight = solve(grid, r + (h >> 1), c + (h >> 1), h >> 1, w >> 1);
            return root;
        }
    }
public:
    Node* construct(vector<vector<int> >& grid) {
        return solve(grid, 0, 0, grid.size(), grid[0].size());
    }
};

int main() {
    Solution sol;
    return 0;
}