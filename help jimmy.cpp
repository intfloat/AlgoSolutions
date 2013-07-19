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

const int INF = 999999;

int main(){  	
	int t;
	cin>>t;
	while(t--){
		int n, x, y, maxi;
		int dp[1100][2];
		for(int i=0; i<1100; i++)
		for(int j=0; j<2; j++)
			dp[i][j] = INF;
		cin>>n>>x>>y>>maxi;
		int len = n+2;
		
		vector<pair<int, pair<int, int> > > v;
		v.push_back(make_pair(0, make_pair(-INF, INF)));
		v.push_back(make_pair(y, make_pair(x, x)));
		int xx, yy, h;
		for(int i=0; i<n; i++){
			cin>>xx>>yy>>h;
			v.push_back(make_pair(h, make_pair(xx, yy)));
		}
		sort(v.begin(), v.end());
		
		dp[0][0]=dp[0][1]=0;
		for(int i=1; i<len; i++){
			int index;
			int hei=v[i].first, left=v[i].second.first, right=v[i].second.second;
			// left side
			for(int j=i-1; j>=0; j--){
				if(left>=v[j].second.first && left<=v[j].second.second){
					index = j;
					break;
				}
			}
			if(hei-v[index].first > maxi)
				dp[i][0] = INF;
			else if(index == 0)
				dp[i][0] = hei;
			else{
				dp[i][0] = (hei-v[index].first)+
						min(dp[index][0]+left-v[index].second.first, 
						dp[index][1]+v[index].second.second-left);
			}
			
			// right side, 
			// binary search will speed up, but there is no need to use it
			for(int j=i-1; j>=0; j--){
				if(right>=v[j].second.first && right<=v[j].second.second){
					index = j;
					break;
				}
			}
			if(hei-v[index].first > maxi)
				dp[i][1] = INF;
			else if(index == 0)
				dp[i][1] = hei;
			else{
				dp[i][1] = (hei-v[index].first)+
						min(dp[index][0]+right-v[index].second.first, 
						dp[index][1]+v[index].second.second-right);
			}// end else
		}// end for loop
		cout<<dp[len-1][0]<<endl;
	}
	system("pause");
	return 0;
}
