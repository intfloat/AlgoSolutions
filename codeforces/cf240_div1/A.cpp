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
	int n, k;
	cin>>n>>k;
	if (k == 0) {
		if (n == 1) {
			cout<<1<<endl;
			return 0;
		}
		else {
			cout<<-1<<endl;
			return 0;
		}
	}	
	if (k<n/2 || n==1){
		cout<<-1<<endl;
		return 0;
	}
	int remain = k - (n/2 - 1);
	cout<<remain<<" "<<2*remain;
	int t = 2*remain+1;
	for (int i=0; i<n-2; i++) cout<<" "<<t+i;
	cout<<endl;
	return 0;
}
