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
#include <cassert>
using namespace std;

int main(){
	int n;
	double points[15][15];
	double equa[15][15];
	cin>>n;
	for(int i=0; i<n+1; i++) {
		for(int j=0; j<n; j++) cin>>points[i][j];
	}
	for(int i=0; i<n; i++) {
		// equation formed by point 0 and point i+1
		for(int j=0; j<n; j++) {
			equa[i][j] = -2*points[0][j] + 2*points[i+1][j];
		}
		equa[i][n] = 0;
		for(int j=0; j<n; j++)
			equa[i][n] += points[i+1][j]*points[i+1][j] - points[0][j]*points[0][j];
	}
	double tmp[15];
	
	// gaussian elimination
	for(int i=0; i<n; i++) {
		double mx = -1;
		int index = -1;
		for(int j=i; j<n; j++) {
			if(fabs(equa[j][i]) > mx) {
				mx = fabs(equa[j][i]);
				index = j;
			}
		}
		assert(index >= i);
		// swap two rows
		memcpy(tmp, equa[i], sizeof(tmp));
		memcpy(equa[i], equa[index], sizeof(equa[i]));
		memcpy(equa[index], tmp, sizeof(equa[index]));

		assert(fabs(equa[i][i]) > 1e-6);
		for(int j=0; j<n; j++) {
			if (i == j) continue;			
			for(int k=i+1; k<n+1; k++)
				equa[j][k] += -(equa[j][i]/equa[i][i])*equa[i][k];
			equa[j][i] = 0;
		}
	}
	for(int i=0; i<n; i++) {
		cout<<fixed<<setprecision(3)<<(equa[i][n]/equa[i][i]);
		if (i < n-1) cout<<" ";
	}
	cout<<endl;
	return 0;
}
