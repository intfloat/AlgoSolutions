#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    int N;
    scanf("%d", &N);
    vector<int> id(N);
    FOR(i, N) scanf("%d", &id[i]);
    vector<bool> visited(N, false);
    vector<int> dis(N, 0);    
    long long res = 0;
    FOR(i, N) {
        int mx = -1;
        int idx = -1;
        FOR(j, N) {
            if (!visited[j] && dis[j] > mx) {
                mx = dis[j];
                idx = j;
            }
        }
        // assert(mx >= 0);
        visited[idx] = true;
        res += mx;
        FOR(j, N) dis[j] = max(dis[j], id[idx] ^ id[j]);
    }
    printf("%lld\n", res);
    return 0;
}
