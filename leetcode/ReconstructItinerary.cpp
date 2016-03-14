#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        map<string, vector<string> > mp;
        for (int i = 0; i < (int)tickets.size(); ++i) {
            mp[tickets[i].first].push_back(tickets[i].second);
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            sort((it->second).begin(), (it->second).end(), greater<string>());
        }
        vector<string> res;
        stack<string> st;
        // find euler path
        st.push("JFK");
        while (!st.empty()) {
            string tp = st.top();
            if (mp.find(tp) == mp.end()) {
                res.push_back(tp);
                st.pop();
            }
            else {
                vector<string>& arr = mp[tp];
                st.push(arr.back());
                arr.pop_back();
                if (arr.empty()) {
                    mp.erase(tp);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {
    return 0;
}
