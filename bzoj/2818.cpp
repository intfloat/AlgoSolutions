#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
typedef long long ll;
const int MAX_N = 10000005;
int miu[MAX_N], N;
bool visited[MAX_N];
vector<int> prime;
inline void calc_miu() {
    for (int i = 0; i <= N; ++i) {
        miu[i] = 0; visited[i] = false;
    }
    miu[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (!visited[i]) {
            prime.push_back(i);
            miu[i] = -1;
        }
        for (int j = 0; j < (int)prime.size() && prime[j] * i <= N; ++j) {
            int tmp = i * prime[j];
            visited[tmp] = true;
            if (i % prime[j] == 0) break;
            else miu[tmp] = -miu[i];
        }
    }
}
int main() {
    scanf("%d", &N);
    calc_miu();
    ll res = 0;
    for (int j = 0; j < (int)prime.size(); ++j) {
        int nn = N / prime[j];
        for (int i = 1; i <= nn; ++i) {
            res += miu[i] * (ll)(nn / i) * (ll)(nn / i);
        }
    }
    printf("%lld\n", res);
    return 0;
}
