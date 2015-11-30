class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n <= 0) {
            return vector<int>();
        }
        vector<vector<int> > g(n);
        vector<int> fa(n, -1);
        for (int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i].first, v = edges[i].second;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        queue<int> q;
        q.push(0);
        vector<int> arr;
        while (!q.empty()) {
            int tp = q.front(); q.pop();
            arr.push_back(tp);
            for (int i = 0; i < (int)g[tp].size(); ++i) {
                int to = g[tp][i];
                if (to == fa[tp]) continue;
                fa[to] = tp;
                q.push(to);
            }
        }
        vector<multiset<int, greater<int> > > h(n);
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < (int)arr.size(); ++i) {
            int f = fa[arr[i]];
            h[arr[i]].insert(0);
            int val = *h[arr[i]].begin();
            if (f >= 0) {
                h[f].insert(val + 1);
            }
        }

        reverse(arr.begin(), arr.end());
        for (int i = 0; i < (int)arr.size(); ++i) {
            int f = fa[arr[i]];
            if (f >= 0) {
                auto it = h[f].begin();
                int val = *h[f].begin();
                if (*h[arr[i]].begin() + 1 == val) {
                    ++it;
                    val = *it;
                }
                h[arr[i]].insert(val + 1);
            }
        }
        vector<int> mx(n);
        for (int i = 0; i < n; ++i) {
            mx[i] = *h[i].begin();
        }
        int mn = *min_element(mx.begin(), mx.end());
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (mx[i] == mn) {
                res.push_back(i);
            }
        }
        return res;
    }
};
