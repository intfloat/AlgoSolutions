class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ptr = 0;
        int mx = 0;
        while (ptr + 3 <= A.size()) {
            int mid = ptr;
            while (mid + 1 < A.size() && A[mid + 1] > A[mid]) ++mid;
            if (mid == ptr) {
                ptr = mid + 1;
                continue;
            }
            int right = mid;
            while (right + 1 < A.size() && A[right + 1] < A[right]) ++right;
            if (right == mid) {
                ptr = mid + 1;
                continue;
            }
            mx = max(mx, right - ptr + 1);
            ptr = right;
        }
        return mx;
    }
};
