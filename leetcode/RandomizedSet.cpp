class RandomizedSet {
private:
    map<int, int> htable;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (this->htable.find(val) != this->htable.end()) {
            return false;
        } else {
            this->htable[val] = nums.size();
            nums.push_back(val);
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (this->htable.find(val) == this->htable.end()) {
            return false;
        }
        int pos = this->htable[val];
        if (pos + 1 != (int)this->nums.size()) {
            int t = this->nums.back();
            this->htable[t] = pos;
            swap(nums.back(), nums[pos]);
        }
        this->htable.erase(val);
        this->nums.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return this->nums[random() % this->nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
