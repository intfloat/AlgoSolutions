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
    int t;
    double pi = 3.141592653;
    cin>>t;
    for(int i=1; i<=t; i++){
        double v, d;
        cin>>v>>d;
        double res = asin(9.8*d/(v*v))/2.0;
        res = (res/pi)*180.0;
        cout<<"Case #"<<i<<": "<<fixed<<setprecision(7)<<res<<endl;
    }
    return 0;
}
