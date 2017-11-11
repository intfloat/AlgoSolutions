class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        const char genes[4] = {'A', 'C', 'G', 'T'};
        set<string> visited, bank_set;
        for (int i = 0; i < bank.size(); ++i) {
            bank_set.insert(bank[i]);
        }
        queue<pair<string, int> > q;
        q.push({start, 0});
        visited.insert(start);
        while (!q.empty()) {
            pair<string, int> tp = q.front();
            q.pop();
            string cur = tp.first;
            int step = tp.second;
            for (int i = 0; i < 8; ++i) {
                char c = cur[i];
                for (int j = 0; j < 4; ++j) {
                    if (genes[j] != c) {
                        cur[i] = genes[j];
                        if (visited.find(cur) != visited.end() || bank_set.find(cur) == bank_set.end()) {
                            continue;
                        }
                        if (cur == end) {
                            return step + 1;
                        }
                        q.push({cur, step + 1});
                        visited.insert(cur);
                    }
                }
                cur[i] = c;
            }
        }
        return -1;
    }
};
