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
	int n, m;
	bool row[1005], col[1005];
	memset(row, true, sizeof(row));
	memset(col, true, sizeof(col));
	cin>>n>>m;
	int x, y;
	for(int i=0; i<m; i++){
		cin>>x>>y;
		row[x]=false; col[y]=false;
	}
	long long res = 0;
	
	for(int j=2; j<=((n+1)/2); j++){
		vector<pair<int, int> >	 v1, v2;

		if(n%2==1 && j==((n/2)+1)){
			v1.push_back(make_pair(1, j));
			v1.push_back(make_pair(n, n+1-j));
			v1.push_back(make_pair(j, n));
			v1.push_back(make_pair(n+1-j, 1));
			int tmp1 = 0;
			for(int i=0; i<4; i++){
				if(i>1 && row[v1[i].first]==true )
					tmp1++;
				else if(i<=1 && col[v1[i].second]==true)
					tmp1++;
			}
			res += min(1, tmp1);
			continue;
		}

		v1.push_back(make_pair(1, j));
		v1.push_back(make_pair(n, n+1-j));
		v1.push_back(make_pair(j, n));
		v1.push_back(make_pair(n+1-j, 1));
		int tmp1 = 0;
		for(int i=0; i<4; i++){
				if(i>1 && row[v1[i].first]==true )
					tmp1++;
				else if(i<=1 && col[v1[i].second]==true)
					tmp1++;
		}
		v2.push_back(make_pair(j, 1));
		v2.push_back(make_pair(n+1-j, n));
		v2.push_back(make_pair(n, j));
		v2.push_back(make_pair(1, n+1-j));
		int tmp2 = 0;
		for(int i=0; i<4; i++){
				if(i<=1 && row[v2[i].first]==true )
					tmp2++;
				else if(i>1 && col[v2[i].second]==true)
					tmp2++;
		}
		if(tmp1 > tmp2){
			for(int i=0; i<4; i++){
				if(row[v1[i].first]==true && col[v1[i].second]==true){
					row[v1[i].first]=false;
					col[v1[i].second]=false;
				}
			}
		}
		if(tmp1 < tmp2){
			for(int i=0; i<4; i++){
				if(row[v2[i].first]==true && col[v2[i].second]==true){
					row[v2[i].first]=false;
					col[v2[i].second]=false;
				}
			}
		}
		
		res += max(tmp1, tmp2);
	}
	cout<<res<<endl;
	//system("pause");
	return 0;
}
