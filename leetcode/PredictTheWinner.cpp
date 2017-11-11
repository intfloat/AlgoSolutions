#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int> > player1(sz, vector<int>(sz + 1));
        vector<vector<int>> player2(sz, vector<int>(sz + 1));
        for (int len = 1; len <= sz; ++len) {
            for (int i = 0; i + len <= sz; ++i) {
                int sum = accumulate(nums.begin() + i, nums.begin() + i + len, 0);
                // for player1
                if (len == 1) {
                    player1[i][len] = nums[i];
                } else {
                    player1[i][len] = max(sum - player2[i + 1][len - 1], sum - player2[i][len - 1]);
                }
                // for player 2
                if (len == 1) {
                    player2[i][len] = nums[i];
                } else {
                    player2[i][len] = max(sum - player1[i + 1][len - 1], sum - player1[i][len - 1]);
                }
            }
        }
        return player1[0][sz] * 2 >= accumulate(nums.begin(), nums.end(), 0);
    }
};
