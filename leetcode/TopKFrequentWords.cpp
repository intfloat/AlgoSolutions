class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> word_cnt;
        for (auto& w : words) {
            ++word_cnt[w];
        }

        vector<pair<int, string> > freq_word_pairs;
        for (auto& it : word_cnt) {
            freq_word_pairs.push_back({-it.second, it.first});
        }
        sort(freq_word_pairs.begin(), freq_word_pairs.end());

        vector<string> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(freq_word_pairs[i].second);
        }
        return res;
    }
};
