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

// Constructive algorithm
int main(){	
	int res[100005];
	int n;
	cin>>n;
	if((n%4)==2 || (n%4)==3){
		cout<<-1<<endl;
		return 0;
	}
	if(n%2 == 1)
		res[(n+1)/2] = (n+1)/2;
	for(int i=1; i<=n/2; i+=2){
		res[i] = i+1;
		res[i+1] = n-i+1;
		res[n-i+1] = n-i;
		res[n-i] = i;
	}
	for(int i=1; i<=n; i++)
		cout<<res[i]<<" ";
	cout<<endl;
	//system("pause");
	return 0;
}

