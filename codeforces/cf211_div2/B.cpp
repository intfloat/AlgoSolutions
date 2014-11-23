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
    int n, k, arr[150005];
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int mn = 0;
    int res = 0;
    for(int i=0; i<k; i++)
        mn += arr[i];
    int cur = mn;
    for(int i=k; i<n; i++){
        cur = cur+arr[i]-arr[i-k];
        if(cur < mn){
            mn = cur;
            res = i-k+1;
        }
    }
    cout<<res+1<<endl;
	return 0;
}
