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
	int t;
	long long N, M, row, col, K;
	cin>>t;
	for (int i=1; i<=t; i++) {
		cin>>N>>M>>K;		
		long long res = 0;
		for (row = 1; row <= N; row++) {
			if ((row*M) <= K) col = M;
			else col = (K/row);
			long long r = K - (row*col);
			if (r >= col) continue;
			// cout<<"row, col, r: "<<row<<" "<<col<<" "<<r<<endl;
			if (col > M) continue;
			if (r>0 && (row+1)>N) continue;
			long long cur = (row*col*(row-1)*(col-1))/4 + (row*r*(r-1))/2;
			res = max(res, cur);
		}
		swap(N, M);
		for (row = 1; row <= N; row++) {
			if ((row*M) <= K) col = M;
			else col = (K/row);
			long long r = K - (row*col);
			if (r >= col) continue;
			// cout<<"row, col, r: "<<row<<" "<<col<<" "<<r<<endl;
			if (col > M) continue;
			if (r>0 && (row+1)>N) continue;
			long long cur = (row*col*(row-1)*(col-1))/4 + (row*r*(r-1))/2;
			res = max(res, cur);
		}
		cout<<"Case #"<<i<<": "<<res<<endl;
	}
	return 0;
}
