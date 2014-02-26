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
	int n, k, tmp;
	deque<pair<int, int> > maxq, minq;
	vector<int> res1, res2;
	scanf("%d%d", &n, &k);
	if(n<k)
		return 0;
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		pair<int, int> t=make_pair(tmp, i);		
		while(maxq.empty()==false && maxq.front().second<=(i-k))
			maxq.pop_front();
		while(maxq.empty()==false 
			&& (maxq.back().first<=tmp || maxq.back().second<=(i-k)))
			maxq.pop_back();
		maxq.push_back(t);		
		
		//t = make_pair(tmp, i);
		while(minq.empty()==false && minq.front().second<=(i-k))
			minq.pop_front();
		while(minq.empty()==false 
			&& (minq.back().first>=tmp || minq.back().second<=(i-k)) )
			minq.pop_back();
		minq.push_back(t);
		
		if(i>=k-1){
			res1.push_back(maxq.front().first);
			res2.push_back(minq.front().first);
		}
	}
	int len = res1.size();
	for(int i=0; i<len; i++)	
		printf("%d ", res2[i]);
	printf("\n");	
	for(int i=0; i<len; i++)	
		printf("%d ", res1[i]);
	printf("\n");
	system("pause");
	return 0;
}
