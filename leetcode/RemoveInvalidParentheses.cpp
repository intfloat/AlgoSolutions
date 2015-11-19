// Actually we can solve it in DP more efficiently, but it's unnecessary and I am lazy...
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        str = s;
        mx = 0;
        dfs1(0, 0, 0);
        dfs2(0, 0, 0);
        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());
        return res;
    }
private:
    string str;
    vector<string> res;
    string cur;
    int mx;
    void dfs1(int pos, int diff, int len) {
        if (pos == (int)str.size()) {
            if (diff == 0) mx = max(len, mx);
            return;
        }
        if (len + (int)str.size() - pos <= mx) {
            return;
        }
        if (str[pos] == '(') {
            dfs1(pos + 1, diff + 1, len + 1);
        }
        else if (str[pos] == ')' && diff > 0) {
            dfs1(pos + 1, diff - 1, len + 1);
        }
        if (str[pos] != '(' && str[pos] != ')') {
            dfs1(pos + 1, diff, len + 1);
        }
        else {
            dfs1(pos + 1, diff, len);
        }
    }
    void dfs2(int pos, int diff, int len) {
        if (pos == (int)str.size()) {
            if (len == mx && diff == 0) res.push_back(cur);
            return;
        }
        if (len + (int)str.size() - pos < mx) {
            return;
        }
        if (str[pos] == '(') {
            cur.push_back(str[pos]);
            dfs2(pos + 1, diff + 1, len + 1);
            cur.pop_back();
        }
        else if (str[pos] == ')' && diff > 0) {
            cur.push_back(str[pos]);
            dfs2(pos + 1, diff - 1, len + 1);
            cur.pop_back();
        }
        if (str[pos] != '(' && str[pos] != ')') {
            cur.push_back(str[pos]);
            dfs2(pos + 1, diff, len + 1);
            cur.pop_back();
        }
        else {
            dfs2(pos + 1, diff, len);
        }
    }
};
