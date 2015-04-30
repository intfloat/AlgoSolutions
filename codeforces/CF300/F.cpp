#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), res(n + 1, 0);
    FOR(i, n) cin >> arr[i];
    for (int i = 1; i < n; ++i) {
        int up = min(i - 1, static_cast<int>(sqrt(i - 1)) + 1);
        // first element as parent
        if (arr[i] < arr[0]) ++res[i];
        // as parent
        for (int j = 1; j <= up; ++j) {
            if (arr[i] >= arr[j]) continue;
            int right = (i - 1) / j;
            int left = (i - 1) / (j + 1);
            if (left >= right) continue;
            ++res[left + 1]; --res[right + 1];
        }
        // as k value
        for (int j = 1; j <= up; ++j) {
            int parent = (i - 1) / j;
            if (parent <= up || arr[i] >= arr[parent]) continue;
            ++res[j]; --res[j + 1];
        }
    }
    for (int i = 1; i < n; ++i) {
        res[i] = res[i - 1] + res[i];
        cout << res[i] << " ";    
    }
    cout << endl;
    return 0;
}
