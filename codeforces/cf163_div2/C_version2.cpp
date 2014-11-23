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

//constructive algorithm does work
int main(){
	int n;
	pair<int, int> pos[1005];
	//store the final result
	vector< pair<int, int> > order;
	vector<int> type;
	cin>>n;
	//read in position
	for(int i=0; i<n-1; i++)
		cin>>pos[i].first>>pos[i].second;
	int scale = n;
	bool empty[1005];
	int res = 0;
	while(scale > 1){
		memset(empty, true, sizeof(empty));
		int emp;
		for(int i=0; i<n-1; i++){
			//find a column with 1
			if((pos[i].first <= scale) && (pos[i].second <= scale))
				empty[pos[i].second] = false;						
		}
		//if last column is empty, then there is no need to swap
		if(empty[scale] == false){
			//find a blank column
			for(int i=1; i<=scale; i++){
				if(empty[i] == true){
					emp = i;
					break;
				}
			}
			res++;
			type.push_back(2);
			order.push_back(make_pair(emp, scale));
			//cout<<2<<" "<<emp<<" "<<scale<<endl;
			//update pairs
			for(int i=0; i<n-1; i++){
				if(pos[i].second == scale)
					pos[i].second = emp;
			}
		}//end if clause
		for(int i=0; i<n-1; i++){
			if(pos[i].first>scale || pos[i].second>scale)
				continue;
			if(pos[i].first == scale)
				break;
			else if(pos[i].first < scale){
				res++;
				int tmp = pos[i].first;
				type.push_back(1);
				order.push_back(make_pair(tmp, scale));
				//cout<<1<<" "<<tmp<<" "<<scale<<endl;
				//update pairs
				for(int j=0; j<n-1; j++){
					if(pos[j].first == scale)
						pos[j].first = tmp;
					else if(pos[j].first == tmp)
						pos[j].first = scale;
				}
				break;
			}//end else if clause
		}//end for loop
		
		scale--;
	}
	
	//output results
	cout<<res<<endl;
	int len = type.size();
	for(int i=0; i<len; i++)
		cout<<type[i]<<" "<<order[i].first<<" "<<order[i].second<<endl;	
//	system("pause")	;
	return 0;
}
