class RandomizedCollection {
private:
    map<int, set<int> > mp;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        this->mp[val].insert(this->nums.size());
        this->nums.push_back(val);
        return (this->mp[val].size() == 1);
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (this->mp.find(val) == this->mp.end()) {
            return false;
        }
        if (nums.back() == val) {
            this->mp[val].erase(nums.size() - 1);
            nums.pop_back();
        } else {
            set<int>& st = this->mp[val];
            int pos = *st.begin();
            this->mp[nums.back()].erase(nums.size() - 1);
            this->mp[nums.back()].insert(pos);
            swap(nums.back(), nums[pos]);
            nums.pop_back();
            st.erase(pos);
        }
        if (this->mp[val].empty()) {
            this->mp.erase(val);
        }
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return this->nums[random() % this->nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
