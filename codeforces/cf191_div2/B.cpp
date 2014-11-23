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

// 21 numbers
const int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 
	59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 
	103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163};
vector<int> res;
int n;

void dfs(int step, int remain, long long cur){
	if(cur > 1e7 || remain<0)
		return;
	//if(res.size() > 100000)
	//	return;
	if(remain == 0){
		if(cur < 1e7)
			res.push_back(cur);
		return;
	}
	if(step == 38)
		return;
	long long tmp = 1;
	for(int i=0; i<=6; i++){
		tmp = 1;
		for(int j=0; j<i; j++)
			tmp *= pri[step];
		dfs(step+1, remain-i, cur*tmp);
	}
	return;
}

int main(){		
	cin>>n;
	dfs(0, 6, 1);
	//cout<<res.size()<<endl;
	sort(res.begin(), res.begin()+n);
	for(int i=0; i<n; i++)
		printf("%d ", res[i]);		
	//system("pause");
	return 0;
}
