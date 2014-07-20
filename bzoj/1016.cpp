#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
 
using namespace std;
typedef pair<int, int> edge;
 
// union find class
class UF{
public:
    int p[105];
    int _find(int x){
        if (p[x] == x) return x;
        p[x] = _find(p[x]);
        return p[x];
    }
    bool _union(int x, int y) {
        int px = _find(x);
        int py = _find(y);
        if (px == py) return false;
        p[px] = py;
        return true;
    }
    UF(){
        for(int i=0; i<105; i++) p[i] = i;
    }
    // overwrite assign operator
    UF& operator=(const UF& that) {
        memcpy(p, that.p, sizeof(p));
        return *this;
    }
};
 
int n, m;
const int MOD = 31011;
vector<int> v;
map<int, vector<edge> > g;
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v.push_back(c);
        g[c].push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    int len = unique(v.begin(), v.end()) - v.begin();
    long long res = 1;
    UF cur;
    int cnt = 0;
    for(int i=0; i<len; i++) {
        if (cnt == n-1) break; // already formed a spanning tree
        int num = g[v[i]].size(); // number of same weight edges
        int mx = 0; // max edge can be chosen from current group
        int dcnt = 0; // number of ways to select maximum edge
        UF next = cur;
        for(int j=0; j<(1<<num); j++) {
            int nn = __builtin_popcount(j);
            if(nn < mx) continue;
            UF tmp = cur;
            bool ok = true;
            for (int k=0; k<num; k++) {
                if((1<<k)&j){
                    if (!tmp._union(g[v[i]][k].first, g[v[i]][k].second)) { ok=false; break; }
                }
            }
            if(ok && nn==mx) ++dcnt;
            else if(ok && nn>mx) { dcnt=1; mx=nn; next=tmp; }
        }
        assert(dcnt > 0);
        res = (res * dcnt)%MOD;
        cnt += mx;
        cur = next;
    }
    if (cnt < n-1) cout<<0<<endl;
    else cout<<(res%MOD)<<endl;
    return 0;
}