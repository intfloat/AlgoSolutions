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
int **dpl, **dpr;
pair<int, int> p[1005];
int n, pos[1005], val[1005];

int main(){ 
    //freopen("pogocow.in", "r", stdin);
    //freopen("pogocow.out", "w", stdout);
    int begin = clock();
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d%d", &p[i].first, &p[i].second);
    sort(p+1, p+n+1);
    for(int i=1; i<=n; i++){
        pos[i] = p[i].first;
        val[i] = p[i].second;
    }
    dpl = new int*[n+1];
    dpr = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dpl[i] = new int[n+1];
        dpr[i] = new int[n+1];
    }
    memset(dpl, 0, sizeof(dpl));
    memset(dpr, 0, sizeof(dpr));

    int res = -1;
    for(int i=1; i<=n; i++){
        //dpl[i][0] = val[i];
        res = max(res, val[i]);
        if((clock()-begin) > 960)
            break;
        for(int j=i-1; j>0; j--){
            dpl[i][j] = val[j]+val[i];
            int dif = pos[i]-pos[j];
            int k = j-1;
            while(k>0 && (pos[j]-pos[k])<=dif){
                dpl[i][j] = max(dpl[i][j], dpl[j][k]+val[i]);
                --k;
            }
            res = max(res, dpl[i][j]);
        }
    }
    for(int i=n; i>=1; i--){
        if((clock()-begin) > 960)
            break;
        for(int j=i+1; j<=n; j++){
            dpr[i][j] = val[j]+val[i];
            int dif = pos[j]-pos[i];
            int k = j+1;
            while(k<=n && (pos[k]-pos[j])<=dif){
                dpr[i][j] = max(dpr[i][j], dpr[j][k]+val[i]);
                ++k;
            }
            res = max(res, dpr[i][j]);
        }
    }
    cout<<"time: "<<(clock()-begin)<<endl;
    cout<<res<<endl;
    return 0;
}
