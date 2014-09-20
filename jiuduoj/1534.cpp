// a pretty clever binary search problem
#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
 
using namespace std;
 
const int MAX_N = 100005;
long long n, m, k;
int A[MAX_N], B[MAX_N];
int main() {
    while (cin >> m >> n >> k) {
        for (int i = 0; i < m; ++i) scanf("%d", A + i);
        for (int i = 0; i < n; ++i) scanf("%d", B + i);
        sort(A, A + m);
        sort(B, B + n);
        int low = A[0] + B[0];
        int up = A[m - 1] + B[n - 1];
        while (low < up) {
            int mid = ((long long)low + up) / 2;
            long long cnt = 0;
             
            // two pointers, only cost linear time
            int pa = 0;
            int pb = n - 1;
            for (pa = 0; pa < m; ++pa) {
                while (A[pa] + B[pb] > mid && pb >= 0) {
                    --pb;
                }
                cnt += pb + 1;
            }
            if (cnt < k) low = mid + 1;
            else up = mid;
        }
        printf("%d\n", low);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1534
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:860 ms
    Memory:2300 kb
****************************************************************/