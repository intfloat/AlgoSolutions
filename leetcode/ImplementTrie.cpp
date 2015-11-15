class TrieNode {
public:
    TrieNode* nt[26];
    bool ok;
    // Initialize your data structure here.
    TrieNode() {        
        ok = false;
        for (int i = 0; i < 26; ++i) nt[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* cur = root;
        for (int i = 0; i < s.size(); ++i) {
            int val = s[i] - 'a';
            if (cur->nt[val] == NULL) {
                cur->nt[val] = new TrieNode();                
            }
            cur = cur->nt[val];
        }
        cur->ok = true;
        return;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* cur = root;
        for (int i = 0; i < key.size(); ++i) {
            int val = key[i] - 'a';
            if (cur->nt[val] == NULL) return false;
            cur = cur->nt[val];
        }
        return cur->ok;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int val = prefix[i] - 'a';
            if (cur->nt[val] == NULL) return false;
            cur = cur->nt[val];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
