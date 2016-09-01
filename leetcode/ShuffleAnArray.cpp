class Solution {
private:
    vector<int> arr;
public:
    Solution(vector<int> nums) {
        this->arr = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->arr;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = this->arr;
        for (int i = 1; i < (int)res.size(); ++i) {
            int pos = random() % (i + 1);
            if (pos != i) {
                swap(res[i], res[pos]);
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
