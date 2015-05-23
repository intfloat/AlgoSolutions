#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const int MAX_N = 5000005;
vector<int> cnt;
void preprocess() {
    ll val = 0;
    for (int i = 2; i < MAX_N; ++i) {
        if (!cnt[i]) {            
            val = i;
            while (val < MAX_N) {
                for (int j = val; j < MAX_N; j += val)
                    ++cnt[j];
                val *= i;
            }
        }
    }
    for (int i = 2; i < MAX_N; ++i) cnt[i] += cnt[i - 1];
    return;
}
int main() {
    int t, a, b;
    cnt.resize(MAX_N);
    fill(cnt.begin(), cnt.end(), 0);
    preprocess();
    scanf("%d", &t);
    FOR(i, t) {
        scanf("%d %d", &a, &b);
        if (b == 1) printf("%d\n", cnt[a]);
        else printf("%d\n", cnt[a] - cnt[b]);
    }
    return 0;
}
