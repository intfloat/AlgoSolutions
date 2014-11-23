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
	int n, m, a[100005];
	bool assigned[100005];
	memset(assigned, false, sizeof(assigned));
	int sum = 0;
	int v, x, yi, qi, t;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		scanf("%d", a+i);
	for(int i=0; i<m; i++){
		scanf("%d", &t);
		if(t==1){
			scanf("%d%d", &v, &x);
			if(assigned[v]==false)
				a[v] = x-sum;
//				assigned[v] = true;

		}
		else if(t==2){
			scanf("%d", &yi);			
			sum += yi;
		}
		else if(t==3){
			scanf("%d", &qi);
			cout<<a[qi]+sum<<endl;
		}
	}
	//system("pause");
	return 0;
}
