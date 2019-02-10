#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
private:
    vector<int> parent;
    void merge(int i, int j) {
        int root_i = this->find(i);
        int root_j = this->find(j);
        parent[root_i] = root_j;
    }
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = this->find(parent[i]);
        }
        return parent[i];
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        parent.resize(n);
        FOR(i, n) parent[i] = i;
        FOR(i, n) FOR(j, n) {
            if (M[i][j]) {
                this->merge(i, j);
            }
        }
        set<int> root;
        FOR(i, n) root.insert(this->find(i));
        return root.size();
    }
};

int main() {
    Solution solution;
    return 0;
}