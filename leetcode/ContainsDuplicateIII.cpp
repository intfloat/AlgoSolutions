typedef long long ll;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int sz = nums.size();
        if (k == 0 || sz <= 1) return false;
        multiset<ll> st;
        multiset<ll>::iterator it;
        for (int i = 0; i < sz; ++i) {
            it = st.lower_bound((ll)nums[i] - t);
            if (it == st.end() || *it > (ll)nums[i] + t) {
                if (i >= k) st.erase(st.find(nums[i - k]));
                st.insert(nums[i]);
            }
            else return true;
        }
        return false;
    }
};
