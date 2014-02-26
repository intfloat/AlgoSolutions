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
	set<pair<int, int> >::iterator ptr, fo, ba;	
	ptr = record.find(make_pair(power, id));
	fo = record.end();
	fo--;
	if(ptr == record.begin()){
		fo = ptr;
		fo++;
		printf("%d %d\n", ptr->second, fo->second);
	}
	// else if(ptr == record.end())
	// actuallt end() does not point to any valid element
	// so it is a potential problem, but test data is too weak
	else if(ptr == fo){
		ba = ptr;
		ba--;
		printf("%d %d\n", ptr->second, ba->second);
	}
	else{
		fo = ptr; fo++;
		ba = ptr; ba--;
		if((fo->first - ptr->first)<(ptr->first - ba->first))
			printf("%d %d\n", ptr->second, fo->second);
		else
			printf("%d %d\n", ptr->second, ba->second);
	}
	return;
}

int main(){		
	int n;
	scanf("%d", &n);
	record.insert(make_pair(1000000000, 1));
	for(int i=0; i<n; i++){
		int power, id;
		scanf("%d%d", &id, &power);		
		record.insert(make_pair(power, id));
		solve(power, id);
	}
	//system("pause");
	return 0;
}
