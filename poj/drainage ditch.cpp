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

int n, m, net[205][205];
int ptr[205];

bool augment(){
	queue<int> q;
	bool check[205];
	memset(check, false, sizeof(check));
	q.push(1); check[1]=true;
	while(q.empty() == false){
		int tmp = q.front();		
		q.pop();
		for(int i=1; i<=m; i++){
			//cout<<net[tmp][i]<<endl;
			if(check[i]==false && net[tmp][i]>0){
				check[i]=true;
				q.push(i);
				ptr[i] = tmp;
				if(i==m)
					return true;
			}
		}// end for loop
	}// end while loop
	
	return false;
}

int main(){		
	while(cin>>n>>m){
		int source, dest, cap;
		memset(net, 0, sizeof(net));		
		memset(ptr, 0, sizeof(ptr));
		for(int i=0; i<n; i++){
			cin>>source>>dest>>cap;
			// there may be several pipes between same pair of points
			net[source][dest] += cap;
			// this line should not exist
			//net[dest][source] = -cap;
		}
		int result = 0;
		// find reasonable path
		while(augment() == true){
			//cout<<"here"<<endl;
			vector<int> v;
			int tmp = m;
			while(ptr[tmp] != 0){
				v.push_back(tmp);
				tmp = ptr[tmp];
			}
			v.push_back(tmp);
			
			int mini = INT_MAX;
			for(int i=v.size()-1; i>0; i--)
				mini = min(mini, net[v[i]][v[i-1]]);
			for(int i=v.size()-1; i>0; i--){
				net[v[i]][v[i-1]] -= mini;
				net[v[i-1]][v[i]] += mini;
			}
			result += mini;
			memset(ptr, 0, sizeof(ptr));
		}
		cout<<result<<endl;
	}
	system("pause");
	return 0;
}
