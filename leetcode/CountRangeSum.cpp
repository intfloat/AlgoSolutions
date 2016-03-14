// O(NlgNlgN) time complexity
class Solution {
private:
    int low, up, n;
    vector<int> arr;
    vector<int> pre;
    int get(int l, int r) {
        if (l == 0) return pre[r];
        else return pre[r] - pre[l - 1];
    }
    int solve(vector<int>& nums, int l, int r) {
        if (l > r) return 0;
        if (l == r) return (nums[l] >= this->low && nums[l] <= this->up);
        int mid = (l + r) / 2;
        int res = solve(nums, l, mid) + solve(nums, mid + 1, r);
        for (int i = mid + 1; i <= r; ++i) {
            arr[i] = nums[i];
        }
        // sort(arr.begin() + mid + 1, arr.begin() + r + 1);
        bool flag = true;
        int val = get(l, mid);
        for (int i = l; i <= mid; ++i) {
            if (nums[i] == val && flag) {
                arr[i] = val;
                flag = false;
            }
            else arr[i] = val - nums[i];
        }
        sort(arr.begin() + l, arr.begin() + mid + 1);
        int pup = r, plow = r;
        for (int i = l; i <= mid; ++i) {
            while (pup > mid && arr[pup] + arr[i] > this->up) --pup;
            while (plow > mid && arr[plow] + arr[i] >= this->low) --plow;
            res += pup - plow;
        }
        for (int i = mid + 1; i <= r; ++i) {
            nums[i] += val;
        }
        sort(nums.begin() + l, nums.begin() + r + 1);
        return res;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->low = lower;
        this->up = upper;
        this->n = nums.size();
        this->arr.resize(n);
        this->pre.resize(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) pre[i] = nums[i];
            else pre[i] = pre[i - 1] + nums[i];
        }
        return solve(nums, 0, n - 1);
    }
};
