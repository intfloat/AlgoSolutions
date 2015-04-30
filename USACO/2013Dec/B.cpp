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

int main(){
    //freopen("vacation.in", "r", stdin);
    //freopen("vacation.out", "w", stdout);
    int INF = 600000000;
    int N, M, K, Q;
    int g[205][205];
    int ans[205][205];
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            g[i][j] = INF;
            ans[i][j] = INF;
        }
    }
    for(int i=0; i<=N; i++) g[i][i]=0;
    int s, d, cost;
    for(int i=0; i<M; i++){
        scanf("%d%d%d", &s, &d, &cost);
        --s; --d;
        g[s][d] = min(cost, g[s][d]);
    }
    // floyd algorithm
    for(int k=0; k<N; k++)
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
    for(int i=K; i<N; i++){
        for(int j=K; j<N; j++){
            for(int t=0; t<K; t++)
                ans[i][j] = min(ans[i][j], g[i][t]+g[t][j]);
        }
    }
    int number = 0;
    long long res = 0;
    long long cur = 0;
    for(int i=0; i<Q; i++){
        scanf("%d%d", &s, &d);
        --s; --d;        
        if(s<K || d<K) cur = g[s][d];
        else cur = ans[s][d];
        if(cur < INF){
            ++number;
            res += cur;
        }
        //cout<<cur<<endl;
    }
    cout<<number<<endl;
    cout<<res<<endl;
    return 0;
}
