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
	vector<int> res[105];
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=1; j<=n; j++){
			if(i%2 == 0)
				res[j].push_back(i*n+j);
			else
				res[n-j+1].push_back(i*n+j);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<res[i].size(); j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
//	system("pause");
	return 0;
}
