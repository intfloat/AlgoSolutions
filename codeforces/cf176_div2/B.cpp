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
	long long n, k;
	long long res = 0;
	cin>>n>>k;
	//就漏了这一个特殊情况。。。我真是太二了。。。。 
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	n--;
	long long maxi = ((k-1)*k)/2;
	if(n > maxi){
		cout<<-1<<endl;
		return 0;
	}
	k--;
	while(n > k){
		n -= k;
		k--;
		res++;
	}
	res++;
	cout<<res<<endl;
	//system("pause");
	return 0;
}

