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
	int res[105], n;
	res[1]=1; res[2]=2; res[3]=4;
	// actually we can solve this problem without using recursive method
	for(int i=4; i<105; i++)
		res[i] = res[i-1]+res[i-2]+res[i-3];
	while(cin>>n && n)
		cout<<res[n]<<endl;
	system("pause");
	return 0;
}
