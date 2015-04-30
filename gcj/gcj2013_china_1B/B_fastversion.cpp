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

int main(){ 
    int t;
    int x1, y1, x2, y2;    
    cin>>t;
    for(int i=1; i<=t; i++){
        int blk;
        cin>>blk;
        vector<int> x, y;
        vector<long long> sumx, sumy;
        vector<pair<int, int> > po;
        x.clear(); y.clear(); po.clear();
        sumx.clear(); sumy.clear();
        pair<int, int> res;
        long long dis = 1ll<<62;
        for(int j=0; j<blk; j++){
            cin>>x1>>y1>>x2>>y2;
            for(int xx=x1; xx<=x2; xx++)
                for(int yy=y1; yy<=y2; yy++){
                    x.push_back(xx);
                    y.push_back(yy);
                    po.push_back(make_pair(xx, yy));
                }
        }
        sort(po.begin(), po.end());
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        sumx.push_back(x[0]); sumy.push_back(y[0]);
        int len = po.size();
        for(int j=1; j<len; j++){
            sumx.push_back(sumx[j-1]+x[j]);
            sumy.push_back(sumy[j-1]+y[j]);
        }

        // iterate for every single point
        for(int j=0; j<len; j++){
            int curx = po[j].first;
            int cury = po[j].second;
            int tx = lower_bound(x.begin(), x.end(), curx)-x.begin();
            int ty = lower_bound(y.begin(), y.end(), cury)-y.begin();
            long long cost = (long long)(tx+1)*curx - sumx[tx]
                -(long long)(len-tx-1)*curx + (sumx[len-1]-sumx[tx]);
            cost += (long long)(ty+1)*cury - sumy[ty]
                -(long long)(len-ty-1)*cury + (sumy[len-1]-sumy[ty]);
            if(cost < dis){
                dis = cost;
                res = po[j];
            }
        }

        cout<<"Case #"<<i<<": "<<res.first
            <<" "<<res.second<<" "<<dis<<endl;      
    }
    return 0;
}
