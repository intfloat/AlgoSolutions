#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
int N;
inline int get_A(const vector<int>& arr, const int& median) {
    vector<int> sm(N);
    sm[0] = arr[0] % median;
    for (int i = 1; i < N; ++i) {
        sm[i] = (sm[i - 1] + arr[i]) % median;
    }
    map<int, int> cnt;
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        ++cnt[sm[i]];
        ret += cnt[sm[i]] - 1;
        ret += (sm[i] == 0);
    }
    return ret;
}
inline int get_B(const vector<int>& arr) {
    int up = 0;
    FOR(i, N) {
        if (arr[i] <= up + 1) {
            up += arr[i];
        }
        else return up + 1;
    }
    return up + 1;
}
inline void solve() {
    scanf("%d", &N);
    vector<int> arr(N);
    FOR(i, N) scanf("%d", &arr[i]);
    vector<int> ori = arr;
    sort(arr.begin(), arr.end());
    int median = arr[N / 2];
    int A = get_A(ori, median);
    int B = get_B(arr);
    printf("%d\n", abs(A - B));
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
