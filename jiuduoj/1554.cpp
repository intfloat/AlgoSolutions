#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;
int main() {
    int n, target;
    vector<int> arr;
    map<int, int> hash;
    pair<int, int> res;
    while (scanf("%d", &n) != EOF) {
        res.first = res.second = -1;
        bool ok = false;
        arr.resize(n);
        FOR(i, n) scanf("%d", &arr[i]);
        scanf("%d", &target);        
        hash.clear();
        hash[arr[n - 1]] = n - 1;
        if (arr[n - 1] == target) {
            res = make_pair(n, n);            
            ok = true;
        }
        for (int i = n - 2; i >= 0; --i) {
            arr[i] += arr[i + 1];
            int tmp = arr[i] - target;
            if (hash.find(tmp) != hash.end()) {
                res = make_pair(i + 1, hash[tmp]);
                hash[arr[i]] = i;
                ok = true;
                continue;
            }
            hash[arr[i]] = i;
            if (arr[i] == target) {
                res = make_pair(i + 1, n);
                ok = true;
            }            
        }
        if (!ok) printf("No\n");
        else printf("%d %d\n", res.first, res.second);
    }
    return 0;
}
