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
using namespace std;
const int MAXN = 4000005;
long long fmul[2][MAXN], fadd[2][MAXN];
int n, m, w;

// initialize two Fenwick trees
void init(){
    memset(fmul, 0, sizeof(fmul));
    memset(fadd, 0, sizeof(fadd));
}

// add val to pos
void update(long long f[MAXN], int pos, long long val, int id){
    if(pos==0) return;
    // you probably need to change this
    int end = n;
    if(id!=0) end = m;
    while(pos <= end){
        f[pos] += val;
        pos += pos&(-pos);
    }
}
// query sum in range [1, pos] in a single Fenwick tree
long long query(long long f[MAXN], int pos){
    long long sum = 0;
    while(pos > 0){
        sum += f[pos];
        pos -= pos&(-pos);
    }
    return sum;
}

// add val to [1, pos]
void updateSingle(int id, int pos, long long val){
    if(pos == 0) return;
    update(fadd[id], pos, val*pos, id);
    update(fmul[id], 1, val, id);
    update(fmul[id], pos, -val, id);
}

// add val to [l, r]
void updateRange(int id, int l, int r, long long val){
    updateSingle(id, r, val);
    updateSingle(id, l-1, -val);
}

long long querySingle(int id, int pos){
    long long res = query(fadd[id], pos) + pos*query(fmul[id], pos);
    return res;
}

// query sum in [left, right]
long long queryRange(int id, int left, int right){
    long long res = querySingle(id, right)-querySingle(id, left-1);
    return res;
}

int main(){ 
    scanf("%d%d%d", &n, &m, &w);
    init();
    for(int i=0; i<w; i++){
        int type;
        cin>>type;
        int x1, y1, x2, y2;
        long long v;
        if(type == 0){
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            cin>>v;
            //cin>>x1>>y1>>x2>>y2>>v;
            updateRange(0, x1, x2, ((long long)(y2-y1+1))*v);
            updateRange(1, y1, y2, ((long long)(x2-x1+1))*v);
        }
        else{
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            long long ans = queryRange(0, 1, n)-queryRange(0, 1, x1-1)
                -queryRange(0, x2+1, n)-queryRange(1, 1, y1-1)
                -queryRange(1, y2+1, m);
            cout<<ans<<endl;
        }
    }
    return 0;
}
