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
	long long n, k, res;
	cin>>n>>k;
	if(n%2 == 0){
		if(k<=(n/2))
			res = 2*k-1;
		else
			res = (k-(n/2))*2;
	}
	else{
		if(k<=(n/2+1))
			res = 2*k-1;
		else
			res = (k-n/2-1)*2;
	}
	cout<<res<<endl;
	//system("pause");
	return 0;
}
