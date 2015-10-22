#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 2e5, inf = 2e18;
int a[maxn], b[maxn];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i], a[i] *= b[i];
    int l = 0, r = 1 + *max_element(a, a + n);
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        int t = 0;
        for(int i = 0; i < n; i++)
            t += max((int)0, (a[i] - m + b[i] - 1) / b[i]);
        if(t >= k)
            l = m;
        else
            r = m;
    }
    l = r;
    for(int i = 0; i < n; i++)
        k -= max((int)0, (a[i] - l + b[i] - 1) / b[i]),
        a[i] -= max((int)0, (a[i] - l + b[i] - 1) / b[i]) * b[i];
    set<pair<int, int>> que;
    for(int i = 0; i < n; i++)
        que.insert({-a[i], i});
    if(n == 1)
        a[0] -= min(a[0], b[0] * k);
    else
    while(k--)
    {
        int v = que.begin()->second;
        if(a[v] == 0)
            break;
        que.erase(que.begin());
        a[v] -= b[v];
        que.insert({-a[v], v});
    }
    for(int i = 0; i < n; i++)
        cout << a[i] / b[i] << " ";

    return 0;
}
