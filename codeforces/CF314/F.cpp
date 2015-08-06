#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
struct Node {
    int x, y;
    string type;
};
ll dp[75][75];
int n, k;
vector<Node> arr;
inline bool check(int x1, int x2, int l, int r) {
    FOR(i, k) {
        if (arr[i].x < l || arr[i].x > r || arr[i].y < l || arr[i].y > r) continue;
        if ((arr[i].x == x1 && arr[i].y == x2)
            || (arr[i].y == x1 && arr[i].x == x2)) {
            if (arr[i].type == "<" || arr[i].type == ">") return false;
        }
        if ((arr[i].x == x1 || arr[i].x == x2) && arr[i].y != x1 && arr[i].y != x2) {
            if (arr[i].type == ">" || arr[i].type == "=" || arr[i].type == ">=") return false;
        }
        if ((arr[i].y == x1 || arr[i].y == x2) && arr[i].x != x1 && arr[i].x != x2) {
            if (arr[i].type == "<" || arr[i].type == "=" || arr[i].type == "<=") return false;
        }
    }
    return true;
}
ll solve(int l, int r) {
    if (l > r) return 1;
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    dp[l][r] = 0;
    if (check(l, r, l, r)) dp[l][r] += solve(l + 1, r - 1);
    if (l + 1 != r && check(l, l + 1, l, r)) {
        dp[l][r] += solve(l + 2, r);
    }
    if (l + 1 != r && check(r - 1, r, l, r)) {
        dp[l][r] += solve(l, r - 2);
    }
    // cout << "DEBUG: " << l << " " << r << " " << dp[l][r] << endl;
    return dp[l][r];
}
int main() {
    cin >> n >> k;
    arr.resize(k);
    FOR(i, k) {
        cin >> arr[i].x >> arr[i].type >> arr[i].y;
        if (arr[i].x == arr[i].y && (arr[i].type == "<" || arr[i].type == ">")) {
            cout << 0 << endl;
            return 0;
        }
    }
    memset(dp, -1, sizeof dp);
    cout << solve(1, 2 * n) << endl;
    return 0;
}
