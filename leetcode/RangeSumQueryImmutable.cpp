class NumArray {
public:
    NumArray(vector<int> &nums) {
        arr = nums;
        for (int i = 1; i < (int)arr.size(); ++i) {
            arr[i] += arr[i - 1];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return arr[j];
        }
        else {
            return arr[j] - arr[i - 1];
        }
    }
private:
    vector<int> arr;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

