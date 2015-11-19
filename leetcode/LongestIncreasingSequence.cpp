class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> st;
        for (int i = 0; i < (int)nums.size(); ++i) {
            set<int>::iterator it = st.lower_bound(nums[i]);
            if (it == st.end()) {
                st.insert(nums[i]);
            }
            else if (*it > nums[i]) {
                st.erase(it);
                st.insert(nums[i]);
            }
        }
        return (int)st.size();
    }
};
