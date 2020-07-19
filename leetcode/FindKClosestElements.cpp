class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int mid = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (mid == arr.size()) --mid;
        else if (mid - 1 >= 0 && abs(x - arr[mid - 1]) <= abs(x - arr[mid])) --mid;

        int left = mid - 1, right = mid + 1;
        while (right - left - 1 < k) {
            if (left < 0) {
                ++right;
            } else if (right >= arr.size()) {
                --left;
            } else if  (abs(arr[left] - x) <= abs(arr[right] - x)) {
                --left;
            } else {
                ++right;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};
