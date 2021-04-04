class Solution {
private:
    int n;
    vector<int> parent;
    int find_root(int idx) {
        if (parent[idx] < 0) {
            return idx;
        }
        int root = find_root(parent[idx]);
        parent[idx] = root;
        return root;
    }
    void merge_root(int u, int v) {
        parent[u] = v;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        this->n = edges.size();
        this->parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = -1;
        }

        vector<int> res;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int root_u = find_root(u);
            int root_v = find_root(v);
            if (root_u == root_v) {
                res = {u, v};
                return res;
            } else {
                merge_root(root_u, root_v);
            }
        }

        // never reach here
        return res;
    }
};
