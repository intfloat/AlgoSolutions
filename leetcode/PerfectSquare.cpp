// 1820 ms
typedef pair<int, int> pii;
class Solution {
public:
    int numSquares(int n) {
        vector<int> arr;
        queue<pii> q;
        set<int> st;
        for (int i = 1; i * i <= n; ++i) {
            arr.push_back(i * i);
            q.push(make_pair(i * i, 1));
            st.insert(i * i);
        }
        int root = (int)sqrt(n);
        if (n == root * root) return 1;
        while (!q.empty()) {
            pii tp = q.front(); q.pop();
            for (int i = 0; i < (int)arr.size(); ++i) {
                int val = tp.first + arr[i];
                if (val == n) return tp.second + 1;
                if (val > n || st.find(val) != st.end()) continue;
                st.insert(val);
                q.push(make_pair(val, tp.second + 1));
            }
        }
        return -1;
    }
};
