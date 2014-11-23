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
	int a[100005], b[100005], c[100005];
	cin>>n;
	if(n%2 == 0){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0; i<n; i++){
		a[i] = i;
		if(2*i < n)
			b[n-i-1] = i*2;		
	}
	for(int i=0; i<n; i++){
		if(n-(2*(i+1))>0)
			b[i] = n-2*(i+1);
	}
	for(int i=0; i<n; i++)
		c[i] = (a[i]+b[i])%n;
		
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<c[i]<<" ";
	cout<<endl;
	
	//system("pause");
	return 0;
}
