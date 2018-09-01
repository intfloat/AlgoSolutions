#include <bits/stdc++.h>
using namespace std;

// forward: key -> <val, frequency, timestamp>
// backward: <frequency, timestamp, key>
typedef pair<int, int> pii;
class LFUCache {
private:
    int capacity;
    map<int, pair<int, pii> > key2val;
    set<pair<pii, int> > records;
    int timestamp;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->timestamp = 0;
    }

    int get(int key) {
        if (key2val.find(key) != key2val.end()) {
            pair<int, pii> data = key2val[key];
            this->records.erase(make_pair(data.second, key));
            data.second.first += 1;
            data.second.second = this->timestamp;
            key2val[key] = make_pair(data.first, data.second);
            records.insert(make_pair(data.second, key));

            ++this->timestamp;
            return data.first;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (this->capacity <= 0) {
            return;
        }

        if (key2val.find(key) == key2val.end()) {
            if (key2val.size() >= this->capacity) {
                pair<pii, int> tp = *records.begin();
                records.erase(records.begin());
                key2val.erase(tp.second);
            }
            key2val[key] = make_pair(value, make_pair(1, this->timestamp));
            records.insert(make_pair(make_pair(1, this->timestamp), key));
        } else {
            pair<int, pii> data = key2val[key];
            records.erase(make_pair(data.second, key));
            data.first = value;
            data.second.first += 1;
            data.second.second = this->timestamp;
            key2val[key] = data;
            records.insert(make_pair(data.second, key));
        }
        ++this->timestamp;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

 int main() {
    int capacity = 2;
    LFUCache cache(capacity);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3.
    cache.put(4, 4);    // evicts key 1.
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4
    return 0;
 }