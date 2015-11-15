#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public: 

    int findkth(int a[], int n, int b[], int m, int k) {        
        if (m <= 0) return a[k - 1];
        if (n <= 0) return b[k - 1];
        if (k <= 1) return min(a[0], b[0]);     
        int mid = m / 2 + n / 2 + 1;    
        if (b[m / 2] >= a[n / 2]) {
            if (mid >= k) return findkth(a, n, b, m / 2, k);
            else return findkth(a + n / 2 + 1, n - (n / 2 + 1), b, m, k - (n / 2 + 1));
        }
        else {
            if (mid >= k) return findkth(a, n / 2, b, m, k);
            else return findkth(a, n, b + m / 2 + 1, m - (m / 2 + 1), k - (m / 2 + 1));
        }
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2) return findkth(A, m, B, n, (total + 1) / 2);         
        else return 0.5 * (findkth(A, m, B, n, total / 2) + findkth(A, m, B, n, (total / 2) + 1));      
    }
};
