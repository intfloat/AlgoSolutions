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
	long long arr[100005];
	cin>>n;
	long long num = 0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		num += arr[i];
	}
	
	sort(arr, arr+n);
	for(long long i=0; i<n-1; i++) 
		num += 2*(n-i-1)*(i+1)*(arr[i+1]-arr[i]);
		
	long long g = __gcd(n, num);
	n = n/g; num = num/g;
	cout<<num<<" "<<n<<endl;
	//system("pause");
	return 0;
}
