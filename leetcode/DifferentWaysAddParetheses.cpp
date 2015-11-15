class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) {
            return vector<int>();
        }
        vector<char> op;
        vector<int> number;
        int cur = 0;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] >= '0' && input[i] <= '9') {
                cur = cur * 10 + (input[i] - '0');
            }
            else {
                number.push_back(cur);
                op.push_back(input[i]);
                cur = 0;
            }
        }
        number.push_back(cur);
        int sz = number.size();
        vector<vector<vector<int> > > dp(sz, vector<vector<int> >(sz));
        for (int i = 0; i < sz; ++i) {
            dp[i][i].push_back(number[i]);
        }
        vector<int>::iterator t1, t2;
        for (int len = 2; len <= sz; ++len) {
            for (int i = 0; i + len <= sz; ++i) {
                int j = i + len - 1;
                for (int k = i; k < j; ++k) {
                    char cc = op[k];
                    for (t1 = dp[i][k].begin(); t1 != dp[i][k].end(); ++t1) {
                        for (t2 = dp[k + 1][j].begin(); t2 != dp[k + 1][j].end(); ++t2) {
                            if (cc == '+') dp[i][j].push_back((*t1) + (*t2));
                            else if (cc == '-') dp[i][j].push_back((*t1) - (*t2));
                            else if (cc == '*') dp[i][j].push_back((*t1) * (*t2));
                        }
                    }
                }
            }
        }
        sort(dp[0][sz - 1].begin(), dp[0][sz - 1].end());
        return dp[0][sz - 1];
    }
};
