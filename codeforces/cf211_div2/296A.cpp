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

// Most frequent number should  not exceed half of array size
int main(){		
	int arr[1005], n;
	bool okay = true;
	memset(arr, 0, sizeof(arr));
	cin>>n;
	for(int i=0; i<n; i++){
		int tmp;
		cin>>tmp;
		arr[tmp]++;
	}
	for(int i=0; i<1005; i++){
		if(arr[i] > (n+1)/2)
			okay = false;
	}
	if(okay == false)	
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;	
	//system("pause");
	return 0;
}
