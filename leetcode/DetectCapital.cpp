#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0, lower = 0;
        for (int i = 0; i < word.size(); ++i) {
            upper += (word[i] >= 'A' && word[i] <= 'Z');
            lower += (word[i] >= 'a' && word[i] <= 'z');
        }
        return (upper == word.size()) || (lower == word.size()) || (upper == 1 && word[0] >= 'A' && word[0] <= 'Z');
    }
};
