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
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
using namespace std;

// solution is too slow, this is a sad news.
long long x1[1005], y1[1005], x2[1005], y2[1005];
pair<long long, long long> res;
long long dis;
long long record[1005], number[1005];


long long counter(long long x, long long y){
    return (x*y*(x+y-2))/2;
}

long long manDis(long long x, long long y, int p1, int p2){
    long long res = 0;
    if(p1==p2){
        res = counter(abs(x-x1[p2])+1, abs(y-y1[p2])+1)+counter(abs(x-x1[p2])+1, abs(y-y2[p2]))
            +counter(abs(x-x2[p2]), abs(y-y1[p2])+1)+counter(abs(x-x2[p2]), abs(y-y2[p2]));
        res += (x2[p2]-x)*(y-y1[p2]+1) + (x-x1[p2]+1)*(y2[p2]-y) + 2*(x2[p2]-x)*(y2[p2]-y);
        return res;
    }

    if(x>x1[p2] && x<x2[p2]){
        res += min(abs(y-y1[p2]), abs(y-y2[p2]))*number[p2];
        res += counter(x-x1[p2]+1, y2[p2]-y1[p2]+1);
        res += counter(x2[p2]-x, y2[p2]-y1[p2]+1);
        res += (x2[p2]-x)*(y2[p2]-y1[p2]+1);
        return res;
    }

    else if(y>y1[p2] && y<y2[p2]){
        res += min(abs(x-x1[p2]), abs(x-x2[p2]))*number[p2];
        res += counter(x2[p2]-x1[p2]+1, y-y1[p2]+1);
        res += counter(x2[p2]-x1[p2]+1, y2[p2]-y);
        res += (x2[p2]-x1[p2]+1)*(y2[p2]-y);
        return res;
    }

    long long xx = min(abs(x-x1[p2]), abs(x-x2[p2]));
    long long yy = min(abs(y-y1[p2]), abs(y-y2[p2]));
    long long distance = abs(xx)+abs(yy);
    res = distance*number[p2] + record[p2];

    return res;
}

int main(){ 
    int t;    
    cin>>t;
    for(int i=1; i<=t; i++){
        int blk;
        cin>>blk;
        dis = 1000000000000000000LL;
        long long x, y;
        for(int j=0; j<blk; j++){
            cin>>x1[j]>>y1[j]>>x2[j]>>y2[j];
            x = x2[j]-x1[j]+1;
            y = y2[j]-y1[j]+1;
            record[j] = (x*y*(x+y-2))/2;
            number[j] = x*y;
//            cout<<j<<" "<<record[j]<<endl;
        }

        for(int j=0; j<blk; j++){
            for(long long xx=x1[j]; xx<=x2[j]; xx++){
                for(long long yy=y1[j]; yy<=y2[j]; yy++){
                    long long cur = 0;
                    for(int k=0; k<blk; k++){
                       cur += manDis(xx, yy, j, k);    
                    }
                    //cout<<"test: "<<xx<<" "<<yy<<" "<<cur<<endl;
                    pair<long long, long long> tmp = make_pair(xx, yy);
                    if(cur < dis){
                        dis = cur;
                        res = tmp;
                    }
                    else if(cur==dis && tmp<res)
                        res = tmp;
                }
            }
        }

        cout<<"Case #"<<i<<": "<<res.first
            <<" "<<res.second<<" "<<dis<<endl;      
    }
    return 0;
}
