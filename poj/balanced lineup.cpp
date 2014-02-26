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

int arr_max[50005][32], arr_min[50005][32],n, q;

void rmq_init(){
	// dynamic programming method
	for(int i=1; i<30; i++)
	for(int j=0; (j+(1<<i)-1)<n; j++){
		arr_max[j][i] = max(arr_max[j][i-1], arr_max[j+(1<<(i-1))][i-1]);
		arr_min[j][i] = min(arr_min[j][i-1], arr_min[j+(1<<(i-1))][i-1]);
	}
	return;
}

void query(int left, int right){
	int len = right-left+1;
	int k=0;
	while((1<<(k+1)) < len)
		k++;
	int maxi = max(arr_max[left][k], arr_max[right-(1<<k)+1][k]);
	int mini = min(arr_min[left][k], arr_min[right-(1<<k)+1][k]);
//	cout<<"maxi: "<<maxi<<" mini: "<<mini<<endl;
	printf("%d\n", maxi-mini);
	return;
}

int main(){			
	scanf("%d%d", &n, &q);
	for(int i=0; i<n; i++){
		scanf("%d", arr_max[i]);
		arr_min[i][0] = arr_max[i][0];
	}
	rmq_init();
	for(int i=0; i<q; i++){
		int left, right;
		scanf("%d%d", &left, &right);
		query(left-1, right-1);
	}
	system("pause");
	return 0;
}
