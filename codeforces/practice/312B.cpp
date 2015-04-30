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
    double p1, p2;
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    p1 = (double)a/b;
    p2 = (double)c/d;
    double res = p1/(p1+p2-p1*p2);
    cout<<fixed<<setprecision(10)<<res<<endl;
//  system("pause");
    return 0;
}
