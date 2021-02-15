class MapSum {
private:
    map<string, int> mp;
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        this->mp[key] = val;
    }

    int sum(string prefix) {
        int res = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            string key = it->first;
            int val = it->second;
            if (key.size() < prefix.size()) {
                continue;
            }

            bool match = true;
            for (int i = 0; i < (int)prefix.size(); ++i) {
                if (prefix[i] != key[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                res += val;
            }
        }

        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
