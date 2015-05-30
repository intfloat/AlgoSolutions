#include <algorithm>
#include <cassert>
using namespace std;
const int MAXN = 50005;
int val[MAXN], dp[MAXN][20], N;
void rmq_init() {
    for (int i = 0; i < N; ++i)  
        dp[i][0] = val[i];      
    for (int i = 1; (1 << i) <= N; ++i) {
        for (int j = 0; (j + (1 << i) - 1) < N; ++j) {            
            dp[j][i] = max(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
        }
    }
    return;
}
int query(int left, int right) {
    assert(left <= right);
    int k = 0;  
    int length = right - left + 1;  
    while ((1 << (k + 1)) < length) ++k;
    int mx = max(dp[left][k], dp[right - (1 << k) + 1][k]);  
    return mx;
}

int main() {
    return 0;
}
