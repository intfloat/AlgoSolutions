#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <utility>
using namespace std;
int main() {
    int n, k, ki, x;
    vector<pair<int, int> > arr;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &ki);
        for (int j = 0; j < ki; ++j) {
            scanf("%d", &x);
            arr.push_back(make_pair(x, i));
        }
    }
    sort(arr.begin(), arr.end());
    vector<int> cnt(k, 0);
    int ptr = 0;
    int res = INT_MAX;
    bool ok = false;
    int total = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (!ok) {
            ++cnt[arr[i].second];
            total += (cnt[arr[i].second] == 1);
            if (total == k) {
                res = arr[i].first - arr[0].first;
                ok = true;
            }
        }
        else {
            ++cnt[arr[i].second];
            while (cnt[arr[ptr].second] > 1) {
                --cnt[arr[ptr++].second];
            }
            res = min(res, arr[i].first - arr[ptr].first);
        }
    }
    printf("%d\n", res);
    return 0;
}
