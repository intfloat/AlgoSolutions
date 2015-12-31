typedef pair<int, int> pii;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string res;
        vector<int> mask(n + 1, 0);
        stack<pii> st[26];
        for (int i = n - 1; i >= 0; --i) {
            mask[i] = ((1 << (s[i] - 'a')) | mask[i + 1]);
            st[s[i] - 'a'].push(make_pair(mask[i], i));
        }
        int val = mask[0], ptr = -1;
        vector<bool> used(26, false);
        while (val != 0) {
            for (int i = 0; i < 26; ++i) {
                while (!st[i].empty() && st[i].top().second <= ptr) {
                    st[i].pop();
                }
            }
            for (int i = 0; i < 26; ++i) {
                if (!used[i] && !st[i].empty() && (st[i].top().first & val) == val) {
                    used[i] = true;
                    ptr = st[i].top().second;
                    st[i].pop();
                    val -= (1 << i);
                    res.push_back('a' + i);
                    break;
                }
            }
        }
        return res;
    }
};
