#include <bits/stdc++.h>
using namespace std;
class AllOne {
private:
    map<string, int> mp;
    set<pair<int, string> > st;
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        ++mp[key];
        int val = mp[key];
        if (val - 1 > 0) {
            st.erase({val - 1, key});
        }
        st.insert({val, key});
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (mp.find(key) == mp.end()) {
            return;
        }
        --mp[key];
        int val = mp[key];
        st.erase({val + 1, key});
        if (val == 0) {
            mp.erase(key);
        } else {
            st.insert({val, key});
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (st.empty()) {
            return "";
        }
        return (*st.rbegin()).second;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (st.empty()) {
            return "";
        }
        return (*st.begin()).second;
    }
};

int main() {
    AllOne obj;
    obj.inc("key1");
    cout << obj.getMaxKey() << endl;
    obj.dec("key1");
    cout << obj.getMaxKey() << endl;
    return 0;
}
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
