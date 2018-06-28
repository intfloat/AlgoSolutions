#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int sz = Profits.size();
        vector<pii> items;
        for (int i = 0; i < sz; ++i) {
            items.push_back({Capital[i], Profits[i]});
        }
        sort(items.begin(), items.end());
        multiset<int> st;
        int ptr = 0;
        for (int i = 0; i < k; ++i) {
            while (ptr < sz && items[ptr].first <= W) {
                st.insert(items[ptr].second);
                ++ptr;
            }
            if (st.empty()) {
                break;
            } else {
                int val = *st.rbegin();
                W += val;
                st.erase(st.find(val));
            }
        }
        return W;
    }
};
