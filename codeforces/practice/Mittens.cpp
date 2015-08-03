#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> color(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &color[i]);
    }
    sort(color.begin(), color.end());
    vector<pair<int, int> > res;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        res.push_back({color[i], color[(i + n / 2) % n]});
        cnt += (res[i].first != res[i].second);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}
