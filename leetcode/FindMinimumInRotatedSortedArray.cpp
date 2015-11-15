class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0;
        int right = static_cast<int>(num.size()) - 1;
        while (left + 1 < right) {
            if (num[left] < num[right]) return num[left];
            int mid = (left + right) / 2;
            if (num[mid] > num[left]) left = mid + 1;
            else right = mid;
        }
        return min(num[left], num[right]);
    }
};
