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
    int n, a[100005], b[100005];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", a+i);
    for(int i=0; i<n; i++) scanf("%d", b+i);
    long long res = 0;
    for(int i=0; i<n; i++){
        // b[i]==1 is a special case, take care
        if(2*a[i]>=b[i] && b[i]>1){
            long long cur = b[i]/2;
            cur = cur*(b[i]-cur);
            res += cur;
        }
        else res--;
    }
    cout<<res<<endl;
	return 0;
}
