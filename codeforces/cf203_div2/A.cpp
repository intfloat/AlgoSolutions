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
    int n, m;
    int right[105], wrong[105];
    cin>>n>>m;
    for(int i=0; i<n; i++)
         cin>>right[i];
    for(int i=0; i<m; i++)
        cin>>wrong[i];
    sort(right, right+n);
    sort(wrong, wrong+m);
    int v = max(right[n-1], right[0]*2);
//    if(right[n-1] > right[0]*2){
  //      cout<<-1<<endl;
    //    return 0;
   // }
    //else v = right[n-1];

    if(v < wrong[0])
        cout<<v<<endl;
    else cout<<-1<<endl;
	return 0;
}
