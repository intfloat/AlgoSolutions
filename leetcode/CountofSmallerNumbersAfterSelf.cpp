typedef pair<int, int> pii;
int n;
vector<int> f;
void update(int pos) {
    while (pos <= n) {
        ++f[pos];
        pos += (pos & (-pos));
    }
}
int query(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += f[pos];
        pos -= (pos & (-pos));
    }
    return ret;
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pii> arr;
        n = nums.size();
        for (int i = 0; i < n; ++i) {
            arr.push_back(make_pair(nums[i], i + 1));
        }
        sort(arr.begin(), arr.end());
        f.resize(n + 1);
        fill(f.begin(), f.end(), 0);
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            update(arr[i].second);
            res[arr[i].second - 1] = query(n) - query(arr[i].second);
        }
        return res;
    }
};
