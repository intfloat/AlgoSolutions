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

struct Node{
	int start;
	int end;
	int interval;
};
Node node[200005];
int n;
int cmp(const void* ele1, const void* ele2){
	Node *p1=(Node *)ele1, *p2=(Node *)ele2;
	if((p1->start)==(p2->start))
		return (p1->end)-(p2->end);
	else
		return (p1->start)-(p2->start);
}

long long check(int pos){
	long long res = 0;
	for(int i=0; i<n; i++){
		if(node[i].start > pos)
			continue;
		if(node[i].end < pos){
			res += (node[i].end-node[i].start)/(node[i].interval)+1;
			continue;
		}
		res += ((pos-node[i].start)/(node[i].interval))+1;
	}
	return res;
}

int get(int pos){
	int res = 0;
	for(int i=0; i<n; i++){
		if(node[i].start > pos)
			continue;
		if(node[i].end < pos)
			continue;
		if((pos-node[i].start)%(node[i].interval) == 0)
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
			scanf("%d%d%d", &node[i].start, &node[i].end, &node[i].interval);
			right = max(right, node[i].end);
			left = min(left, node[i].start);
			sum += (node[i].end-node[i].start)/(node[i].interval)+1;
		}
		if(sum%2 == 0){
			printf("Poor QIN Teng:(\n");
			continue;
		}
		//qsort(node, n, sizeof(Node), cmp);
		long long tmp;
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
