class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > g(numCourses, vector<int>());
        int n = numCourses;
        for (int i = 0; i < prerequisites.size(); ++i)
            g[prerequisites[i].second].push_back(prerequisites[i].first);
        vector<int> ind(n, 0);
        vector<bool> finished(n, false);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < g[i].size(); ++j)
                ++ind[g[i][j]];
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (ind[i] == 0) {
                q.push(i);                
                finished[i] = true;
                for (int j = 0; j < g[i].size(); ++j) --ind[g[i][j]];
            }
        }
        while (!q.empty()) {
            int tp = q.front(); q.pop(); ++cnt;
            for (int i = 0; i < g[tp].size(); ++i) {
                int to = g[tp][i];                
                if (finished[to] || ind[to] > 0) continue;
                q.push(to);
                finished[to] = true;
                for (int j = 0; j < g[to].size(); ++j) --ind[g[to][j]];
            }
        }
        return (cnt == n);
    }
};
