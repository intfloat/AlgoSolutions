#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n, x, h;
    cin >> n;
    vector<pair<int, int> > arr(n);
    FOR(i, n) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    int res = 1, pos = arr[0].first;
    for (int i = 1; i < n; ++i) {        
        x = arr[i].first; h = arr[i].second;
        if (x - h > pos) {
            ++res;
            pos = x;
        }
        else if (i == n - 1 || x + h < arr[i + 1].first) {
            ++res;
            pos = x + h;
        }
        else pos = x;
    }
    cout << res << endl;
    return 0;
}
