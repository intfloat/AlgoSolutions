class Solution {
public:
    void reverse_arr(int* begin, int* end) {
        while (begin < end) {
            swap(*begin, *end);
            ++begin; --end;
        }
    }
    
    void rotate(int nums[], int n, int k) {
       k = k % n;
       if (k == 0 || k == n) return;
       reverse_arr(nums, nums + n - k - 1);
       reverse_arr(nums + n - k, nums + n - 1);
       reverse_arr(nums, nums + n - 1);
       return;
    }
};
