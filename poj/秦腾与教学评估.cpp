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


int start[200005];
int end[200005];
int interval[200005];
int n;

int check(int pos){
	int res = 0;
	for(int i=0; i<n; i++){
		if(start[i] > pos)
			continue;
		if(end[i] < pos){
			res += (end[i]-start[i])/(interval[i])+1;
			continue;
		}
		res += ((pos-start[i])/(interval[i]))+1;
	}
	return res;
}

int get(int pos){
	int res = 0;
	for(int i=0; i<n; i++){
		if(start[i] > pos)
			continue;
		if(end[i] < pos)
			continue;
		if((pos-start[i])%(interval[i]) == 0)
			res++;
	}
	return res;
}

int main(){	
	int t;
	scanf("%d", &t);
	while(t--){
		int left = INT_MAX;
		int right = 0;
		long long sum = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d%d%d", start+i, end+i, interval+i);
			right = max(right, end[i]);
			left = min(left, start[i]);
			sum += (end[i]-start[i])/(interval[i])+1;
		}
		if(sum%2 == 0){
			printf("Poor QIN Teng:(\n");
			continue;
		}
		//qsort(node, n, sizeof(Node), cmp);
		int tmp;
		// Binary search 
		while(left < right-1){
			int middle = (left+right)/2;
			tmp = check(middle);			
			if(tmp%2 == 0)
				left = middle+1;
			else
				right = middle;
		}
		if(check(left)%2 == 1)
			cout<<left<<" "<<get(left)<<endl;
		else cout<<right<<" "<<get(right)<<endl;
	}
	system("pause");
	return 0;
}
