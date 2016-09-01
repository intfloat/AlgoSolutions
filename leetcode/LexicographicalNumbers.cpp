class Solution {
private:
    vector<int> res;
    int n;
    void dfs(int cur) {
        for (int i = 0; i <= 9; ++i) {
            int val = cur * 10 + i;
            if (val > n) {
                return;
            } else {
                this->res.push_back(val);
                dfs(val);
            }
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        this->res.clear();
        this->n = n;
        for (int i = 1; i <= min(n, 9); ++i) {
            this->res.push_back(i);
            dfs(i);
        }
        return this->res;
    }
};
