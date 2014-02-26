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

long long L;

long long extended_euclidean(long long a, long long b, long long &x, long long &y){
	if(b==0){
		x = 1;
		y = 0;
		return a;
	}
	long long g = extended_euclidean(b, a%b, x, y);
	long long tmp = x;
	x = y;
	y = tmp - (a/b)*y;
	return g;
}

int main(){		
	long long x, y, m, n;
	cin>>x>>y>>m>>n>>L;
	long long a = (m-n+L)%L;
	long long b = L;
	long long c = (y-x+L)%L;
	long long g = extended_euclidean(a, b, x, y);
	if(c%g != 0){
		cout<<"Impossible"<<endl;
		return 0;
	}
	long long k = c/g;
	x = (x*k);
	if(x < 0)
		x = (L/g-(abs(x)%(L/g)));
	while((x-L/g) > 0)
		x = x%(L/g);
	cout<<x<<endl;
	//system("pause");
	return 0;
}
