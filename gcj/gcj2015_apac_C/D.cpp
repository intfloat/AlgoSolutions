#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
void solve() {
    ll N, K, C, X;
    cin >> N >> K >> C >> X;
    vector<ll> A(N), B(N);
    FOR(i, N) cin >> A[i];
    FOR(i, N) cin >> B[i];
    vector<vector<ll> > arr(N, vector<ll>(N));
    FOR(i, N) FOR(j, N) {
        arr[i][j] = ((i + 1) * A[i] + (j + 1) * B[j] + C) % X;
    }
    deque<pii> dp;
    FOR(i, N) {
        dp.clear();
        FOR(j, N) {
            while (!dp.empty() && dp.front().second <= j - K) dp.pop_front();
            while (!dp.empty() && (dp.back().second <= j - K || arr[i][j] >= dp.back().first)) dp.pop_back();
            dp.push_back(make_pair(arr[i][j], j));
            arr[i][j] = dp.front().first;
        }
    }
    ll res = 0;
    for (int j = K - 1; j < N; ++j) {
        dp.clear();
        FOR(i, N) {
            while (!dp.empty() && dp.front().second <= i - K) dp.pop_front();
            while (!dp.empty() && (dp.back().second <= i - K || arr[i][j] >= dp.back().first)) dp.pop_back();
            dp.push_back(make_pair(arr[i][j], i));
            arr[i][j] = dp.front().first;
            if (i >= K - 1) res += arr[i][j];
        }
    }
    printf("%lld\n", res);
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
