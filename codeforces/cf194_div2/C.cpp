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
	long long n;
	long long res = 0;
	cin>>n;
	long long cur = 1;
	while(n%cur == 0){
		cur = cur*3;
	}
	res = n/cur + 1;
	cout<<res<<endl;
	//system("pause");
	return 0;
}
