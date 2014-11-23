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
	int n;
	pair<int, int> s[100005];
	int a[100005], b[100005];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>s[i].first;
		s[i].second = i;
	}
	sort(s, s+n);
	int begin = (n+2)/3;
	int cur = 0;
	for(int i=begin; i<n; i++){
		if(cur%2 == 0){
			// from 0 to n/3-1
			a[s[i].second] = cur/2;
			// from n/3 to 2*n/3
			b[s[i].second] = s[i].first-cur/2;
		}
		else{
			// from 0 to n/3-1
			b[s[i].second] = cur/2;
			// from n/3 to 2*n/3
			a[s[i].second] = s[i].first - cur/2;
		}
		cur++;
	}
	for(int i=0; i<begin; i++){
		a[s[i].second] = 0;
		b[s[i].second] = s[i].first;
	}
	cout<<"YES"<<endl;
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
	cout<<endl;
	//system("pause");
	return 0;
}
