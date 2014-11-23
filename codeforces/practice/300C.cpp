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
#define MOD 1000000007
using namespace std;

// Fast power by divide and conquer
long long fast_pow(long long num, int p){
	// Boundary conditions
	if(p==0)
		return 1;
	if(p==1)
		return num;
	long long res = fast_pow(num, p/2)%MOD;
	res = (res*res)%MOD;
	if(p%2 == 1)
		res = (res*num)%MOD;
	return res;
}

long long inv(long long num){
	return fast_pow(num, MOD-2);
}

// Multiplicative inverse
int main(){		
	long long fact[1000005];
	long long res = 0;
	long long tmp;
	int a, b, n;
	cin>>a>>b>>n;
	fact[0] = 1;
	fact[1] = 1;
	for(int i=2; i<=n; i++)
		fact[i] = (fact[i-1]*i)%MOD;
	// Brute force process
	for(int i=0; i<=n; i++){
		int sum = a*i+b*(n-i);
		bool check = true;
		while(sum > 0){
			int lsb = sum%10;
			sum = sum/10;
			if(lsb!=a && lsb!=b){
				check = false;
				break;
			}
		}
		if(check == true){
		//	if(i <= n-i)
				tmp = (fact[n]*inv((fact[i]*fact[n-i])%MOD))%MOD;
	//		else
//				tmp[i] = tmp[n-i];
			res = (res+tmp)%MOD;
		}
	}
	cout<<res%MOD<<endl;
	//system("pause");
	return 0;
}
