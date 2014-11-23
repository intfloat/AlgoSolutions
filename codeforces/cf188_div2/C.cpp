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
	long long x, y, m, t, res = 0;
	cin>>x>>y>>m;
	t = max(x, y);
	if(t >= m)
		res = 0;
	else if(x<=0 && y<=0)
		res = -1;
	else{
		long long xx = min(x, y);
		long long yy = max(x, y);
		if(xx < 0){
			res += (-xx)/yy;
			xx += res*yy;
			x = xx;
			y = yy;
		}
		xx = min(x, y);
		yy = max(x, y);
		while(yy < m){
			x = xx + yy;
			y = yy;
			res++;
			xx = min(x, y);
			yy = max(x, y);
		}
	}
	cout<<res<<endl;
	//system("pause");
	return 0;
}
