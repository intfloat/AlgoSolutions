#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
using namespace std;
int n, q;
vector<int> arr;
int solve(int pos, int len) {
    if (len == 0) return pos;
    if ((pos - 1 < 0 || arr[pos] - len > arr[pos - 1])
        && (pos + 1 >= n || arr[pos] + len < arr[pos + 1])) {
        return pos;
    }
    int right = upper_bound(arr.begin(), arr.end(), arr[pos] + len) - arr.begin() - 1;
    int rem = len - (arr[right] - arr[pos]);
    int left = lower_bound(arr.begin(), arr.end(), arr[right] - rem) - arr.begin();
    if (left == right) {
        return left;
    }
    int nrem = arr[left] - (arr[right] - rem);
    if (nrem <= arr[right] - arr[left]) {
        return solve(left, nrem);
    }
    else {
        int d = rem / (arr[right] - arr[left]);
        if (d % 2) return solve(left, rem % (arr[right] - arr[left]));
        else return solve(right, rem % (arr[right] - arr[left]));
    }
}
int main() {
    int pos, len;
    scanf("%d %d", &n, &q);
    arr.resize(n);
    map<int, int> mp, rmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        mp[arr[i]] = i;
        rmp[i] = arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &pos, &len);
        --pos;
        pos = lower_bound(arr.begin(), arr.end(), rmp[pos]) - arr.begin();
        printf("%d\n", mp[arr[solve(pos, len)]] + 1);
    }
    return 0;
}
