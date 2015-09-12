#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    vector<int> val(10);
    FOR(i, 10) scanf("%d", &val[i]);
    sort(val.begin(), val.end(), greater<int>());
    int res = val[0] + val[2] + val[4];
    printf("%d\n", res);
    return 0;
}
