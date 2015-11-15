UglyNumberII.cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st;
        long long res = -1;
        st.insert(1ll);
        for (int i = 0; i < n; ++i) {
            res = *st.begin();
            st.erase(st.begin());
            st.insert(res * 2ll);
            st.insert(res * 3ll);
            st.insert(res * 5ll);
        }
        return (int)res;
    }
};
