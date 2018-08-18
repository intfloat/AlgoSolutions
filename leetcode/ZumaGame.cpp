#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int min_step;
    string removeConsecutiveChars(string s) {
        int idx = 0;
        string ret;
        while (idx < (int)s.size()) {
            int ptr = idx + 1;
            while (ptr < (int)s.size() && s[ptr] == s[idx]) {
                ++ptr;
            }
            if (ptr - idx < 3) {
                for (int i = idx; i < ptr; ++i) {
                    ret.push_back(s[i]);
                }
            }
            idx = ptr;
        }
        if (s.size() != ret.size()) {
            ret = removeConsecutiveChars(ret);
        }
        return ret;
    }

    void dfs(string board, string hand, int used_step) {
        if (board.empty()) {
            this->min_step = min(this->min_step, used_step);
            return;
        }
        if (used_step + 1 >= this->min_step) {
            return;
        }
        for (int i = 0; i < (int)hand.size(); ++i) {
            for (int j = 0; j < (int)board.size(); ++j) {
                if (board[j] == hand[i] && (j == 0 || board[j - 1] != hand[i])) {
                    string new_board = board;
                    new_board.insert(new_board.begin() + j, hand[i]);
                    new_board = this->removeConsecutiveChars(new_board);
                    string new_hand = hand;
                    new_hand.erase(new_hand.begin() + i);
                    dfs(new_board, new_hand, used_step + 1);
                }
            }
        }
    }
public:
    int findMinStep(string board, string hand) {
        this->min_step = hand.size() + 1;
        dfs(board, hand, 0);
        if (this->min_step > (int)hand.size()) {
            return -1;
        } else {
            return this->min_step;
        }
    }
};

int main() {
    string board = "RBYYBBRRB";
    string hand = "YRBGB";
    Solution sol;
    // it should be 3
    cout << sol.findMinStep(board, hand) << endl;
    return 0;
}