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
	double r, h;
	cin>>r>>h;
	double rr = r/2.0;
	double extra = (2.0-sqrt(3.0))*rr;
//	cout<<extra<<endl;
	double res = floor((h+extra)/r);
	res = res*2 + 1;
	if(h >= rr){
		double res2 = floor((h-rr)/r);
		res2 = 2+2*res2;
		res = max(res, res2);
	}
	cout<<(int)res<<endl;
	return 0;
}
