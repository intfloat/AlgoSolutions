#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<int> c2row(26);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < (int)s[i].size(); ++j) {
                c2row[s[i][j] - 'a'] = i;
            }
        }
        vector<string> res;
        for (string& word : words) {
            bool ok = true;
            for (int i = 1; i < (int)word.size(); ++i) {
                char c1 = (word[i] >= 'a') ? word[i] : (word[i] + 'a' - 'A');
                char c2 = (word[i - 1] >= 'a') ? word[i - 1] : (word[i - 1] + 'a' - 'A');
                if (c2row[c1 - 'a'] != c2row[c2 - 'a']) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res.push_back(word);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    for (string& s : sol.findWords(words)) {
        cout << s << endl;
    }
    return 0;
}
