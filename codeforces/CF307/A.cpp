#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> rating(N);
    FOR(i, N) {
        cin >> rating[i];
    }
    vector<int> tt = rating;
    sort(tt.begin(), tt.end());
    FOR(i, N) {
        int cnt = tt.end() - upper_bound(tt.begin(), tt.end(), rating[i]);
        cout << cnt + 1 << " ";
    }
    cout << endl;
    return 0;
}
