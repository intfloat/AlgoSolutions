#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int main() {
    freopen("records.in", "r", stdin);
    freopen("records.out", "w", stdout);
    int N;
    cin >> N;
    vector<string> arr(3);
    vector<string> cont;
    FOR(i, N) {
        FOR(j, 3) cin >> arr[j];
        sort(arr.begin(), arr.end());
        cont.push_back(arr[0] + "$" + arr[1] + "$" + arr[2]);
    }
    sort(cont.begin(), cont.end());
    int mx = 1;
    int ptr = 0;
    while (ptr < cont.size()) {
        int i = ptr + 1;
        while (i < cont.size() && cont[i] == cont[ptr]) ++i;
        mx = max(i - ptr, mx);
        ptr = i;
    }
    printf("%d\n", mx);
    return 0;
}
