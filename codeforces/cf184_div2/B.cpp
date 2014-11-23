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
	long long p, q, a[100];
	int n;
	bool okay = true;	
	cin>>p>>q;
	cin>>n;
	memset(a, 0, sizeof(a));
	for(int i=0; i<n; i++)
		cin>>a[i];
	
	for(int i=0; i<n; i++){	
		if(q==0){
			okay = false;
			break;
		}
		long long tmp = p/q;		
		if(i==n-2 && a[n-1]==1){
			if(tmp != a[i]+1){
				okay = false;
				break;
			}
			else if(p==q*(a[i]+1))
				break;
			else{
				okay = false;
				break;
			}
		}
		if(tmp!=a[i]){
			okay = false;
			break;
		}
		p = p-a[i]*q;
		if(i==n-1 && p!=0){
			okay=false;
			break;
		}
		swap(p, q);
	}
	if(okay == true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	//system("pause");
	return 0;
}
