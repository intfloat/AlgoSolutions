#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
inline void solve() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    int ptr = 0;
    int res = 1;
    while (ptr < arr.size()) {
        int i = ptr + 1;
        while (i < arr.size() && arr[i] - arr[i - 1] == 1) ++i;
        res = max(res, i - ptr);
        ptr = i;
    }
    printf("%d\n", res);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
