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
	vector<int> v;
	bool used[5000];
	memset(used, false, sizeof(used));
	int n;
	cin>>n;
	int pre = 0;
	int next = 0;
	int res = 0;
	for(int i=0; i<n; i++){
		cin>>next;
		for(int j=0; j<(next-pre); j++)
			v.push_back(1);
		v.push_back(0);
		pre = next;
	}
	int len = v.size();
	for(int i=0; i<len; i++){
		if(v[i] == 0){
			res = 0;
			for(int j=i-1; j>=0; j--){
				if(v[j]==1 && used[j]==false){
					used[j] = true;
					res++;
					break;
				}
				else if(v[j]==1 && used[j]==true)
					res++;
			}
			cout<<res<<" ";
		}		
	}
	cout<<endl;

	system("pause");
	return 0;
}
