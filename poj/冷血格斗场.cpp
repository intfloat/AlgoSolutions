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

set<pair<int, int> > record;
void solve(int power, int id){
	set<pair<int, int> >::iterator ptr, left, right;
	ptr = record.find(make_pair(power, id));
	right = record.end(); right--;
	if(ptr == record.begin()){
		right = ptr;
		right++;
		printf("%d %d\n", id, right->second);
		
		// id is already sorted
		if((power == right->first))
			record.erase(right);
		//else if((power == right->first) && (right->first < id))
		//	record.erase(ptr);
	}
	else if(ptr == right){
		left = ptr; left--;
		printf("%d %d\n", id, left->second);
		
		if((power == left->first))
			record.erase(left);
		//else if((power == left->first) && (left->first < id))
		//	record.erase(ptr);
	}
	else{
		left = ptr; left--;
		right = ptr; right++;
		if((right->first - ptr->first)<(ptr->first - left->first))
			printf("%d %d\n", id, right->second);
		else if((right->first - ptr->first)>(ptr->first - left->first))
			printf("%d %d\n", id, left->second);
		else{
			// compare id
			if(right->second < left->second)
				printf("%d %d\n", id, right->second);
			else
				printf("%d %d\n", id, left->second);
		}
		
		// gurantee power is unique in the whole set
		if(power == right->first)
			record.erase(right);
		if(power == left->first)
			record.erase(ptr);
	}
	return;
}

int main(){		
	int n;
	scanf("%d", &n);
	record.insert(make_pair(1000000000, 1));
	for(int i=0; i<n; i++){
		int id, power;
		scanf("%d%d", &id, &power);
		record.insert(make_pair(power, id));
		solve(power, id);
	}
	//system("pause");
	return 0;
}
