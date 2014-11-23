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
	int n = 33333;
	int arr[] = {1, 2, 6};
	cout<<n*3<<endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<n; j++){
			if(i==2 && j==n-1)
				cout<<arr[i]<<endl;
			else
				cout<<arr[i]<<" ";
		}
	}
	return 0;
}
