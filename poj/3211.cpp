#include <vector>
#include <list>
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
using namespace std;

//POJ 3211 washing clothes
//I think dynamic programming strategy will work
//and it really works
int main(){
	int m, n;
	pair<string, int> colors[15];	
	pair<int, string> clothes[105];
	//several test cases... oh my god...
	while(cin>>m>>n && (n!=0 || m!=0)){
	for(int i=0; i<m; i++){
		cin>>colors[i].first;
		colors[i].second = 0;
	}
	for(int i=0; i<n; i++){
		cin>>clothes[i].first>>clothes[i].second;
		for(int j=0; j<m; j++){
			if(clothes[i].second == colors[j].first)
				colors[j].second += clothes[i].first;
		}
	}
	int res = 0;
	bool dp[100005];
	for(int i=0; i<m; i++){
		int upper = colors[i].second/2;
		memset(dp, false, sizeof(dp));
		dp[0]= true;
		vector<int> v;
		v.push_back(0);
		//update for each cloth
		for(int j=0; j<n; j++){
			//color must match
			if(colors[i].first == clothes[j].second){
				int len = v.size();
				for(int k=0; k<len; k++){
					int tmp = v[k]+clothes[j].first;
					//add into vector
					if((tmp<=upper) && (dp[tmp]==false)){
						dp[tmp] = true;
						v.push_back(tmp);
					}//end internal if				
				}
			}//end external if
		}//end for loop
		//choose the nearest value
		for(int j=upper; j>=0; j--){
			if(dp[j] == true){
				//add the larger time value
				res += (colors[i].second-j);			
				break;
			}
		}//end internal for loop
	}//end external for loop
	cout<<res<<endl;
	}	
	return 0;
}
