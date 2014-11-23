//大脑有点混乱，但基本的动态规划思想还是很清楚的，过几天再重写吧…… 
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <string.h>
#define M -10000000
using namespace std;

int main(){
	pair<long long, int> fir, sec;
	int n, q;
	int color[100005], value[100005];
	long long dp[100005];
	scanf("%d%d", &n, &q);
	for(int i=0; i<n; i++)
		scanf("%d", value[i]);
	for(int i=0; i<n; i++)
		scanf("%d", color[i]);
	for(int i=0; i<q; i++){
		int a, b;		
		long long res = -10000000;
		scanf("%d%d", &a, &b);
		memset(dp, M, sizeof(dp));
		fir = make_pair(0, 0);
		sec = make_pair(0, 0);
		
		for(int j=0; j<n; j++){
			//it is alone
			long long cur = value[j]*b;
			if(dp[color[j]] > M)
				cur = max(cur, dp[color[j]] + value[j]*a);			
			/*if(j == 0){
				dp[color[j]] = value[j]*b;
				if(dp[j] >= 0)
					fir = make_pair(dp[j], color[j]);
			}*/
			else{
				//dp[color[j]] = dp[color[j]] + value[j]*a;
				if(fir.second == color[j]){
					dp[color[j]] = max(dp[color[j]], (long long)sec.first + value[j]*b);
					//update greatest pair
					fir.first = max((long long)fir.first, dp[color[j]]);
				}
				else{
					dp[color[j]] = max(dp[color[j]], (long long)fir.first + value[j]*b);
					//update two greatest pairs
					if(dp[color[j]] > fir.first){
						sec = fir;
						fir = make_pair(dp[color[j]], color[j]);
					}
					else if(dp[color[j]] > sec.first)
						sec = make_pair(dp[color[j]], color[j]);
				}					
			}
			res = max(res, dp[color[j]]);
		}
		cout<<max(res, (long long)0)<<endl;
	}	
	return 0;
}
