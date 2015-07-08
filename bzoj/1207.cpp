#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef pair<int, int> point;
inline int dis(point& p1, point& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, point> > arr(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &arr[i].first, &arr[i].second.first, &arr[i].second.second);
    }
    sort(arr.begin(), arr.end());
    vector<int> dp(m, 1);
    for (int i = 1; i < m; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (dis(arr[i].second, arr[j].second) <= abs(arr[i].first - arr[j].first)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    printf("%d\n", *max_element(dp.begin(), dp.end()));
    return 0;
}
