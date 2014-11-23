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
	int c[10];
	memset(c, 0, sizeof(c));
	int n, number;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>number;
		c[number]++;
	}
	if(c[5]!=0 || c[7]!=0 || (c[1]!=n/3)){
		cout<<-1<<endl;
		return 0;
	}
	if(c[6]<c[3] || c[2]<c[4] || ((c[6]-c[3])!=(c[2]-c[4]))){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0; i<c[4]; i++)
		cout<<"1 2 4"<<endl;
	for(int i=0; i<(c[2]-c[4]); i++)
		cout<<"1 2 6"<<endl;
	for(int i=0; i<c[3]; i++)
		cout<<"1 3 6"<<endl;
	return 0;
}
