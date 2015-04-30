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
    cin>>t;
    for (int tt=1; tt<=t; tt++) {
        cout<<"Case #"<<tt<<": ";
        double c, f, x;
        cin>>c>>f>>x;
        double b = 2*c+f*c-f*x;
        double a = c*f;
        double res = 0;
        for (int n=0; ; n++) {
            double cur = n*a+b;
            if (cur > 1e-6) {
                for (int i=0; i<n; i++)
                    res += c/(2+i*f);
                res += x/(2+n*f);
                cout<<fixed<<setprecision(7)<<res<<endl;
                break;
            }
        }
    }
    return 0;
}
