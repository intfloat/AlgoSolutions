#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1000005;
int miu[MAX_N];
bool visited[MAX_N];
vector<int> prime;
inline void calc_miu() {
    memset(miu, 0, sizeof miu);
    memset(visited, false, sizeof visited);
    miu[1] = 1;
    for (int i = 2; i < MAX_N; ++i) {
        if (!visited[i]) {
            prime.push_back(i);
            miu[i] = -1;
        }
        for (int j = 0; j < (int)prime.size() && prime[j] * i < MAX_N; ++j) {
            int tmp = i * prime[j];
            visited[tmp] = true;
            if (i % prime[j] == 0) break;
            else miu[tmp] = -miu[i];
        }
    }
}
int main() {
    calc_miu();
    int N, T;
    scanf("%d", &T);
    for (int tt = 0; tt < T; ++tt) {
        scanf("%d", &N);
        ll res = 3;
        for (int i = 1; i <= N; ++i) {
            res += miu[i] * (ll)(N / i) * (ll)(N / i) * (ll)(N / i + 3);
        }
        printf("%lld\n", res);
    }
    return 0;
}
