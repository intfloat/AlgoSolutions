class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)words[i].size(); ++j) {
                mask[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    res = max(res, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return res;
    }
};
