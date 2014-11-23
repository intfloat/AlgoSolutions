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
	int n, a[105], b[105];
	int res = 0;
	int brand[105], self[105];
	bool okay[105];
	memset(okay, false, sizeof(okay));
	memset(brand, 0, sizeof(brand));
	memset(self, 0, sizeof(self));
	
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i]>>b[i];
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++){
		if(okay[i]==true)
			break;
		if(i==j)
			continue;
		if(b[j]==a[i]){
			okay[i]=true;
			break;
		}
	}
	for(int i=0; i<n; i++){
		if(okay[i]==false)
			res++;
	}
	cout<<res<<endl;
	//system("pause");
	return 0;
}

