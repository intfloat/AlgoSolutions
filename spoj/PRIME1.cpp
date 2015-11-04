#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 100005;
vector<bool> prime(MAX_N, true);
vector<ll> num;
void preprocess() {
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAX_N; ++i) {
        if (prime[i]) {
            num.push_back(i);
            for (ll j = (ll)i * i; j < MAX_N; j += i) {
                prime[j] = false;
            }
        }
    }
}
int main() {
    int T, low, up;
    preprocess();
    scanf("%d", &T);
    vector<bool> ok;
    for (int tt = 0; tt < T; ++tt) {
        scanf("%d %d", &low, &up);
        ok.resize(up - low + 1);
        fill(ok.begin(), ok.end(), true);
        for (int i = 0; i < (int)num.size() && num[i] * num[i] <= up; ++i) {
            int left = max(2 * num[i], low / num[i] * num[i]);
            if (left < low) left += num[i];
            for (int j = left; j <= up; j += num[i]) {
                ok[j - low] = false;
            }
        }
        for (int i = max(2, low); i <= up; ++i) {
            if (ok[i - low]) printf("%d\n", i);
        }
        if (tt + 1 < T) printf("\n");
    }
    return 0;
}
