class MagicDictionary {
private:
    vector<string> dicts;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        this->dicts = dictionary;
    }

    bool search(string searchWord) {
        for (int i = 0; i < (int)this->dicts.size(); ++i) {
            string s = this->dicts[i];
            if (s.size() != searchWord.size()) {
                continue;
            }

            int diff_cnt = 0;
            for (int j = 0; j < searchWord.size(); ++j) {
                diff_cnt += searchWord[j] != s[j];
                if (diff_cnt > 1) {
                    break;
                }
            }
            if (diff_cnt == 1) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
