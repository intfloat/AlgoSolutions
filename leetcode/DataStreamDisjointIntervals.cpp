typedef pair<int, int> pii;
class SummaryRanges {

private:
    set<pii> st;

public:
    /** Initialize your data structure here. */
    SummaryRanges() {}

    void addNum(int val) {
        pii p = make_pair(val, INT_MAX);
        auto it = st.upper_bound(p);
        if (it != st.begin()) {
            --it;
            if ((*it).second >= val) {
                return;
            }
        }
        p.second = val;
        st.insert(p);
        it = st.find(p);
        ++it;
        if (it != st.end() && (*it).first == val + 1) {
            p = make_pair(val, (*it).second);
            st.erase(it);
            st.erase({val, val});
            st.insert(p);
        }
        it = st.find(p);
        if (it == st.begin()) {
            return;
        }
        --it;
        if ((*it).second + 1 == val) {
            pii np = make_pair((*it).first, p.second);
            st.erase(it);
            st.erase(p);
            st.insert(np);
        }
    }

    vector<Interval> getIntervals() {
        vector<Interval> ret;
        for (auto it = st.begin(); it != st.end(); ++it) {
            ret.push_back(Interval((*it).first, (*it).second));
        }
        return ret;
    }
};

// int main() {
//     SummaryRanges obj;
//     vector<int> num = {1, 3, 7, 2, 6};
//     srand(time(NULL));
//     for (int i = 1; i <= 2000; ++i) {
//         obj.addNum(rand() % 10);
//         vector<Interval> res = obj.getIntervals();
//         for (Interval inter : res) {
//             printf("[%d %d] ", inter.start, inter.end);
//         }
//         printf("\n");
//     }
//     return 0;
// }
