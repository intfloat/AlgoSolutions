class Solution {
public:
    int findMin(vector<int> &num) {
        // this is a lazy solution with same worst case time complexity
        // return *min_element(num.begin(), num.end());    
        int left = 0, right = num.size() - 1;
        while (left < right && num[left] >= num[right]) {
            int mid = (left + right) / 2;
            if (num[mid] > num[left]) left = mid + 1;
            else if (num[mid] < num[right]) right = mid;
            else if (num[mid] == num[left]) ++left;
            else if (num[mid] == num[right]) --right;
        }
        return num[left];
    }
};