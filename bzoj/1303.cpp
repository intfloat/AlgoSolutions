#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n, b, pos;
    scanf("%d %d", &n, &b);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] == b) {
            pos = i;
        }
    }
    map<int, int> left, right;
    long long res = 1;
    int c1 = 0, c2 = 0;
    for (int i = pos - 1; i >= 0; --i) {
        c1 += (arr[i] < b);
        c2 += (arr[i] > b);
        res += (c1 == c2);
        ++left[c1 - c2];
    }
    c1 = c2 = 0;
    for (int i = pos + 1; i < n; ++i) {
        c1 += (arr[i] < b);
        c2 += (arr[i] > b);
        res += (c1 == c2);
        ++right[c1 - c2];
    }
    map<int, int>::iterator it;
    for (it = left.begin(); it != left.end(); ++it) {
        res += (long long)(it->second) * (long long)right[-(it->first)];
    }
    printf("%lld\n", res);
    return 0;
}
