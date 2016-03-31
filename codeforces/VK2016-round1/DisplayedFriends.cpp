#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, k, q, type, id;
    scanf("%d %d %d", &n, &k, &q);
    vector<int> val(n + 1);
    FOR(i, n) scanf("%d", &val[i + 1]);
    vector<pii> arr;
    FOR(i, q) {
        scanf("%d %d", &type, &id);
        if (type == 1) {
            arr.push_back({val[id], id});
        }
        else {
            sort(arr.begin(), arr.end(), greater<pii>());
            while ((int)arr.size() > k) {
                arr.pop_back();
            }
            bool ok = false;
            FOR(j, arr.size()) {
                if (arr[j].second == id) {
                    ok = true;
                    break;
                }
            }
            if (ok) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
