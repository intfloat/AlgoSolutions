typedef pair<int, int> pii;
const int ENTER = 1;
const int LEAVE = 0;
struct Event {
    int x, y1, y2, type;
    Event(int _x, int _y1, int _y2, int _t): x(_x), y1(_y1), y2(_y2), type(_t) {}
};
bool cmp(const Event& a, const Event& b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } else {
        return a.type < b.type;
    }
}
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) {
            return false;
        }
        int sz = rectangles.size();
        int mn = rectangles[0][1], mx = rectangles[0][3];
        vector<Event> events;
        for (int i = 0; i < sz; ++i) {
            int x1 = rectangles[i][0], x2 = rectangles[i][2];
            int y1 = rectangles[i][1], y2 = rectangles[i][3];
            mn = min(mn, y1);
            mx = max(mx, y2);
            events.push_back(Event(x1, y1, y2, ENTER));
            events.push_back(Event(x2, y1, y2, LEAVE));
        }
        pii target = {mn, mx};
        sort(events.begin(), events.end(), cmp);
        set<pii> s;
        int ptr = 0;
        while (ptr < (int)events.size()) {
            int i = ptr;
            while (i < (int)events.size() && events[i].x == events[ptr].x) {
                pii val = {events[i].y1, events[i].y2};
                if (events[i].type == ENTER) {
                    auto it = s.lower_bound(val);
                    if (it != s.end() && (*it).first < val.second) {
                        return false;
                    } else if (it != s.end() && (*it).first == val.second) {
                        val.second = (*it).second;
                        s.erase(it);
                        s.insert(val);
                    } else {
                        s.insert(val);
                    }
                    it = s.find(val);
                    if (it != s.begin()) {
                        --it;
                        if ((*it).second > val.first) {
                            return false;
                        } else if ((*it).second == val.first) {
                            s.erase(val);
                            val.first = (*it).first;
                            s.erase(it);
                            s.insert(val);
                        }
                    }
                } else {
                    auto it = s.upper_bound({val.first, INT_MAX});
                    if (s.empty() || it == s.begin()) {
                        return false;
                    }
                    --it;
                    pii cur = *it; s.erase(it);
                    assert(cur.first <= val.first);
                    if (val.second > cur.second) {
                        return false;
                    }
                    pii t1 = {cur.first, val.first};
                    pii t2 = {val.second, cur.second};
                    if (t1.second > t1.first) s.insert(t1);
                    if (t2.second > t2.first) s.insert(t2);
                }
                ++i;
            }
            ptr = i;
            if (s.size() == 1 && *s.begin() == target) {
                continue;
            } else if (i >= (int)events.size() && s.empty()) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }
};
