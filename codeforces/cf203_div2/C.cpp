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
#define point pair<int, int>
#define xx first
#define yy second
using namespace std;

const int SIZE = 100005;

const int cmp(const point& p1, const point& p2){
    if(abs(p1.xx) == abs(p2.xx))
        return abs(p2.yy)-abs(p2.yy);
    return abs(p1.xx)-abs(p2.xx);
}

int main(){		
    int n;
    int res = 0;
    pair<point, point> pos[SIZE];
  //  point p[SIZE];
    cin>>n;
    for(int i=0; i<n; i++){
//        cin>>p[i].xx>>p[i].yy;
        cin>>pos[i].xx.xx>>pos[i].xx.yy;
        if(pos[i].xx.xx < 0)
            pos[i].yy.xx = -1;
        else pos[i].yy.xx = 1;
        if(pos[i].xx.yy < 0)
            pos[i].yy.yy = -1;
        else pos[i].yy.yy = 1;
//        pos[i].yy.xx = -(pos[i].xx.xx < 0);
//        pos[i].yy.yy = -(pos[i].xx.yy < 0);
        if(pos[i].first.first==0 || pos[i].first.second==0)
            res += 4;
        else res += 6;
        pos[i].xx.xx = abs(pos[i].xx.xx);
        pos[i].xx.yy = abs(pos[i].xx.yy);
    }
    cout<<res<<endl;
    //sort(p, p+n, cmp);

    sort(pos, pos+n);

    for(int i=0; i<n; i++){
        int x = pos[i].first.first*pos[i].yy.xx;
        int y = pos[i].first.second*pos[i].yy.yy;
        if(x>0){
            cout<<"1 "<<abs(x)<<" R"<<endl;
            if(y > 0)
                cout<<"1 "<<abs(y)<<" U"<<endl;            
            else if(y < 0)
                cout<<"1 "<<abs(y)<<" D"<<endl;
            cout<<2<<endl;
            if(y > 0)
                cout<<"1 "<<abs(y)<<" D"<<endl;            
            else if(y < 0)
                cout<<"1 "<<abs(y)<<" U"<<endl;
            cout<<"1 "<<abs(x)<<" L"<<endl;
            cout<<3<<endl;
        }
        else if(x<0){
            cout<<"1 "<<abs(x)<<" L"<<endl;
            if(y > 0)
                cout<<"1 "<<abs(y)<<" U"<<endl;            
            else if(y < 0)
                cout<<"1 "<<abs(y)<<" D"<<endl;
            cout<<2<<endl;
            if(y > 0)
                cout<<"1 "<<abs(y)<<" D"<<endl;            
            else if(y < 0)
                cout<<"1 "<<abs(y)<<" U"<<endl;
            cout<<"1 "<<abs(x)<<" R"<<endl;
            cout<<3<<endl;
        }
        // x is 0
        else{
            if(y > 0)
                cout<<"1 "<<abs(y)<<" U"<<endl;
            else if(y < 0)
                cout<<"1 "<<abs(y)<<" D"<<endl;
            cout<<2<<endl;
            if(y > 0)            
                cout<<"1 "<<abs(y)<<" D"<<endl;
            else if(y < 0)
                cout<<"1 "<<abs(y)<<" U"<<endl;
            cout<<3<<endl;
        }
    }
	return 0;
}
