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
	cin>>n;
	long long res = 0;
	for(int i=5; i<=n; i++)
	for(int b=i-1; b>0; b--){
		if(i*i>2*b*b)
			continue;
		int a = sqrt(1.0*i*i-1.0*b*b);
		if(a*a+b*b==i*i)
			res++;
	}
	cout<<res<<endl;
	//system("pause");
	return 0;
}
