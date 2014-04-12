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

const int MOD = 1000000007;
int main(){		
	int t;
	cin>>t;
	long long n;
	for (int i=1; i<=t; i++) {
		cin>>n;
		long long res = 0;
		long long sum = 0;
		if (n%2 == 0) {
			sum = ((n/2)%MOD)*((n+1)%MOD);
			sum %= MOD;
		}
		else {
			sum = (n%MOD)*(((n+1)/2)%MOD);
			sum %= MOD;
		}
		long long a = (n+1)%MOD;
		long long b = (sum-(n%MOD)-1+MOD)%MOD;
		long long n1 = n, n2 = n+1, n3 = 2*n+1;
		if (n1%3 == 0) n1 = n1/3;
		else if(n2%3 == 0) n2 = n2/3;
		else n3 = n3/3;

		if(n1%2 == 0) n1 = n1/2;
		else if(n2%2 == 0) n2 = n2/2;
		else n3 = n3/2;

		n1 %= MOD; n2 %= MOD; n3 %= MOD;
		long long t2 = (n1*n2)%MOD;
		t2 = (t2*n3)%MOD;

		res = (sum*sum)%MOD;
		res = (res*sum)%MOD;		
		// cout<<"total: "<<res<<endl;

		// cout<<"a: "<<a<<endl;
		// cout<<"b: "<<b<<endl;
		long long t3 = (b-2*a+MOD)%MOD;
		long long last = (sum*sum)%MOD+(t3*t2)%MOD;
		// cout<<"here: "<<last<<endl;
		last = last+((((a*a)%MOD-(2*a*b)%MOD+MOD)%MOD)*sum)%MOD;
		last %= MOD;
		// cout<<"here1: "<<last<<endl;
		long long tt = (a*a)%MOD;
		tt = (tt*b)%MOD;
		tt = (tt*n)%MOD;
		last = (last+tt%MOD)%MOD;
		// cout<<"here2: "<<last<<endl;
		last = (3*last)%MOD;
		// cout<<"last: "<<last<<endl;
		res = (res-last+MOD)%MOD;
		cout<<"Case "<<i<<": "<<res<<endl;
	}
	return 0;
}
