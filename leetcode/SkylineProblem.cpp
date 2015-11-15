#define ENTER 0
#define LEAVE 1
typedef pair<int, int> point;
struct Event {
    int x, y, type;
    Event(int _x, int _y, int _t): x(_x), y(_y), type(_t) {}
    bool operator<(const Event& that) const {
        return x < that.x;
    }
};
class Solution {
public:
    vector<point> getSkyline(vector<vector<int> >& buildings) {
        int sz = buildings.size();
        vector<Event> event;
        for (int i = 0; i < sz; ++i) {
            event.push_back(Event(buildings[i][0], buildings[i][2], ENTER));
            event.push_back(Event(buildings[i][1], buildings[i][2], LEAVE));
        }
        sort(event.begin(), event.end());
        vector<point> res;
        multiset<int> st;
        multiset<int>::iterator it;
        for (int i = 0; i < (int)event.size(); ++i) {
            if (event[i].type == ENTER) {
                if (st.empty()) {
                    res.push_back(make_pair(event[i].x, event[i].y));
                }
                else {
                    it = st.end(); --it;
                    if (event[i].y > *it) {
                        res.push_back(make_pair(event[i].x, event[i].y));
                    }
                }
                st.insert(event[i].y);
            }
            else {
                it = st.find(event[i].y);
                st.erase(it);
                if (st.empty()) {
                    res.push_back(make_pair(event[i].x, 0));
                }
                else {
                    it = st.end(); --it;
                    if (event[i].y > *it) {
                        res.push_back(make_pair(event[i].x, *it));
                    }
                }
            }
        }
        int ptr = 0;
        for (int i = 0; i < res.size(); ++i) {
            if (i + 1 < res.size() && res[i].first == res[i + 1].first) {
                continue;
            }
            res[ptr++] = res[i];
        }
        res.resize(ptr);
        vector<point> ret;
        for (int i = 0; i < res.size(); ++i) {
            if (i == 0 || res[i].second != res[i - 1].second) {
                ret.push_back(res[i]);
            }
        }
        return ret;
    }
};
