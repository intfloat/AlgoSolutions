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
	int N, M;
	while(cin>>N>>M) {
		if (N==0 && M==0) break;
		pair<int, int> p1[1005], p2[1005];
		int r[1005], g[1005], b[1005];
		for (int i=0; i<N; i++) {
			cin>>p1[i].first>>p1[i].second;
			cin>>p2[i].first>>p2[i].second;
			cin>>r[i]>>g[i]>>b[i];
		}
		for (int i=0; i<M; i++) {
			int x, y;
			cin>>x>>y;
			bool flag = false;
			for (int j=N-1; j>=0; j--) {
				if (x>=p1[j].first && x<=p2[j].first
					&& y>=p1[j].second && y<=p2[j].second) {
					cout<<r[j]<<" "<<g[j]<<" "<<b[j]<<endl;
					flag = true;
					break;
				}
			}
			if (flag == false) {
				cout<<"255 255 255"<<endl;
			}
		}
	}
	return 0;
}
