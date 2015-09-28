#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
bool cmp(const int a, const int b) {
    return (a % 10) > (b % 10);
}
int main() {
    int n, k, res = 0;
    scanf("%d %d", &n, &k);
    vector<int> skill(n);
    FOR(i, n) {
        scanf("%d", &skill[i]);
        res += skill[i] / 10;
    }
    sort(skill.begin(), skill.end(), cmp);
    int total = 0;
    FOR(i, n) {
        int val = ((skill[i] + 9) / 10) * 10;
        total += 100 - val;
        if (skill[i] % 10 == 0) continue;
        int rem = val - skill[i];
        if (rem > k) {
            k = 0;
            break;
        }
        k -= rem;
        ++res;
    }
    res += min(k, total) / 10;
    printf("%d\n", res);
    return 0;
}
