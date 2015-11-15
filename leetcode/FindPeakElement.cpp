class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int left = 0, right = num.size() - 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1])
                return mid;
            else if (num[mid - 1] > num[mid]) right = mid - 1;
            else left = mid + 1;
        }
        if (num[left] > num[right]) return left;
        else return right;
    }
};
