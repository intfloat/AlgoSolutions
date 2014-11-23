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

// to solve the opposite problem
// and using dynamic programming technique
int main(){		
	int n;
	string a, b;
	long long res = 1;
	long long large=1, small=1, equal=1;
	cin>>n;
	cin>>a>>b;
	
	for(int i=0; i<n; i++){
		if(a[i]=='?')
			res = (res*10)%MOD;
		if(b[i]=='?')
			res = (res*10)%MOD;
	}
	
	for(int i=0; i<n; i++){
		if(a[i]=='?' && b[i]=='?') large = (large*55)%MOD;
		else if(a[i]=='?') large = (large*(b[i]-'0'+1))%MOD;
		else if(b[i]=='?') large = (large*(10+'0'-a[i]))%MOD;
		else if(a[i]>b[i]){ large = 0; break; }
	}
	for(int i=0; i<n; i++){
		if(a[i]=='?' && b[i]=='?') small = (small*55)%MOD;
		else if(a[i]=='?') small = (small*(10+'0'-b[i]))%MOD;
		else if(b[i]=='?') small = (small*(a[i]-'0'+1))%MOD;
		else if(a[i]<b[i]){ small = 0; break; }
	}
	
	for(int i=0; i<n; i++){
		if(a[i]=='?' && b[i]=='?') equal = (equal*10)%MOD;
		else if(a[i]!='?' && b[i]!='?' && a[i]!=b[i]){
			equal = 0;
			break;
		}
	}
	
	res = (res+equal-large-small+MOD*2)%MOD;
	cout<<res<<endl;
	//system("pause");
	return 0;
}
