class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0) return 1;
        int res = A[0];
        int *pos = new int[n];
        int *neg = new int[n];
        if (A[0] > 0) {
            pos[0] = A[0];
            neg[0] = 0;
        }
        else {
            pos[0] = 0;
            neg[0] = A[0];
        }
        for (int i = 1; i < n; ++i) {
            if (A[i] > 0) {
                pos[i] = max(A[i], A[i] * pos[i - 1]);
                neg[i] = min(0, A[i] * neg[i - 1]);
            }
            else {
                pos[i] = max(A[i] * neg[i - 1], 0);
                neg[i] = min(A[i] * pos[i - 1], A[i]);
            }
            res = max(res, neg[i]);
            res = max(res, pos[i]);
        }
        return res;
    }
};
