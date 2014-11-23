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
	int r1, c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;
    if(r1==r2 || c1==c2)
        cout<<1;
    else cout<<2;
    if((r1+c1)==(r2+c2) || (r1-c1)==(r2-c2))
        cout<<" 1";
    else if(((r1+c1)%2) != ((r2+c2)%2))
        cout<<" 0";
    else cout<<" 2";
    int res = max(abs(r2-r1),abs(c2-c1));
    cout<<" "<<res<<endl;
    return 0;
}
