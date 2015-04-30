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

int N, M, Q;
int ans[100005][18];
void dp(){
    for(int j=1; j<18; j++){
        for(int i=1; i<=M; i++){
            int tmp = ans[i][j-1];
            ans[i][j] = ans[tmp][j-1];
        }
    }
    return;
}

int query(int begin, int t){
    int res = begin;
    for(int i=0; i<20; i++){
        if((1<<i) > t) break;
        if((t&(1<<i)) > 0){
            res = ans[res][i];
        }
    }
    return res;    
}

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    scanf("%d%d%d", &N, &M, &Q);
    memset(ans, 0, sizeof(ans));
    for(int i=1; i<=M; i++){
        scanf("%d", ans[i]+0);
        --ans[i][0];
    }
    dp();
    vector<int> v(100005);
    for(int i=1; i<=N; i++){
        int begin = min(M, i);
        int left = 1;
        int right = N-i+1;
        int rec = query(begin, right);
        if(rec > 0){
            v[i] = rec+(N-M+1);
            continue;
        }
        while(left < right){
            int middle = (left+right)/2;
            rec = query(begin, middle);
            if(rec == 0) right = middle;
            else left = middle+1;
        }
        v[i] = left;
    }
    for(int i=0; i<Q; i++){
        int qi;
        scanf("%d", &qi);
        printf("%d\n", N-v[qi]+1);
    }
    return 0;
}
