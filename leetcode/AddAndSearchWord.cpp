class WordDictionary {
private:
    map<int, set<string> > m;
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        m[word.size()].insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        string low = word, up = word;
        int sz = word.size();
        for (int i = 0; i < sz; ++i) {
            if (word[i] == '.') {
                low[i] = 'a';
                up[i] = 'z';
            }
        }
        if (m.find(sz) != m.end() && m[sz].find(low) != m[sz].end()) return true;
        m[sz].insert(low);
        set<string>::iterator it = m[sz].find(low);
        ++it;
        bool ok = false;
        while (it != m[sz].end() && *it <= up) {
            string cur = *it;            
            ok = true;
            for (int i = 0; i < sz; ++i) {
                if (word[i] == '.') continue;
                else if (word[i] != cur[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) break;
            else ++it;
        }
        m[sz].erase(low);
        if (m[sz].empty()) m.erase(sz);
        return ok;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
