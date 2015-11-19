class NumArray {
public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        arr.resize(n + 1);
        fill(arr.begin(), arr.end(), 0);
        for (int i = 0; i < n; ++i) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        ++i;
        int old = sumRange(i - 1, i - 1);
        while (i <= n) {
            arr[i] += val - old;
            i += (i & (-i));
        }
    }

    int sumRange(int i, int j) {
        ++i; ++j;
        return range(j) - range(i - 1);
    }
private:
    vector<int> arr;
    int n;
    int range(int i) {
        if (i == 0) return 0;
        int ret = 0;
        while (i > 0) {
            ret += arr[i];
            i -= (i & (-i));
        }
        return ret;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
