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
    long long n, a, b;
    cin>>n;
    if(n==0){
        cout<<1<<endl;
        return 0;
    }
    a = (long long)(n/sqrt(2.0));
    b = a;
    long long mx = -1;
    for(int i=-50; i<50; i++){
        for(int j=-50; j<50; j++){
            long long cur = (a+i)*(a+i)+(b+j)*(b+j);
            if(cur <= (n*n)) mx = max(mx, a+b+i+j);
        }
    }
    long long res = 4*mx;
    cout<<res<<endl;
    return 0;
}
