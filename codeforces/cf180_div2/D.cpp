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
	int n, m, k;
	int alice[100005], bob[100005];
	cin>>n>>m>>k;
	for(int i=0; i<n; i++)
		cin>>alice[i];
	for(int i=0; i<m; i++)
		cin>>bob[i];
	if(n>m){
		cout<<"YES"<<endl;
		return 0;
	}
	sort(alice, alice+n);
	sort(bob, bob+m);
	int ptr1=n-1, ptr2=m-1;
	while(ptr1>=0){
		if(alice[ptr1]>bob[ptr2]){
			cout<<"YES"<<endl;
			return 0;
		}
		else{
			ptr1--;
			ptr2--;
		}
	}
	
	cout<<"NO"<<endl;
	//system("pause");
	return 0;
}
