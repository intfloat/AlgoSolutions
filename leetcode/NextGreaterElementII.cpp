class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz);
        stack<int> st;
        for (int i = sz - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }
            st.push(nums[i]);
        }
        for (int i = sz - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = -1;
            } else {
                res[i] = st.top();
            }
            st.push(nums[i]);
        }
        return res;
    }
};
