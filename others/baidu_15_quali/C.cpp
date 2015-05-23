#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
unsigned int get() {
    unsigned int val = 0, t;
    char c;
    for (int j = 3; j >= 0; --j) {
        if (j == 0) scanf("%d", &t);
        else scanf("%u %c", &t, &c);        
        val += t << (j * 8);
    }
    return val;
}
void solve() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<unsigned int> arr(N);
    FOR(i, N) arr[i] = get();    
    FOR(i, M) {
        unsigned int mask = get();        
        set<unsigned int> s;
        FOR(j, N) {
            s.insert(mask & arr[j]);
        }
        int res = s.size();
        printf("%d\n", res);
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
