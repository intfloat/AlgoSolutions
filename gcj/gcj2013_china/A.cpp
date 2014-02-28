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
#define BLACK 0
#define GREY 1
#define WHITE 2
using namespace std;

vector<string> names;
vector<int> edge[500];
int flag[500];

int index(string name){
	for(int i=0; i<names.size(); i++){
		if(name == names[i])
			return i;
	}
	names.push_back(name);
	return names.size()-1;
}

int main(){	
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int m;
		cin>>m;
		names.clear();
		bool solution = true;
		for(int j=0; j<500; j++){
			edge[j].clear();
			flag[j] = GREY;
		}
		for(int j=0; j<m; j++){
			string name1, name2;
			int node1, node2;
			cin>>name1>>name2;
			node1 = index(name1); node2 = index(name2);
			edge[node1].push_back(node2);
			edge[node2].push_back(node1);
		}

		int n = names.size();
		for(int j=0; j<n; j++){
			if(flag[j]!=GREY || solution==false)
				continue;
			queue<int> q;
			while(q.empty()==false)
				q.pop();
			flag[j] = BLACK;
			q.push(j);
			while(q.empty()==false && solution==true){
				int node = q.front(); q.pop();
				int len = edge[node].size();
				for(int k=0; k<len; k++){
					int cur = edge[node][k];
					if(flag[cur]==GREY){
						q.push(cur);
						if(flag[node]==BLACK)
							flag[cur] = WHITE;
						else
							flag[cur] = BLACK;
					}
					else if(flag[cur]==flag[node]){
						solution = false;
						break;
					}
				}// end for loop
			}// end while loop
		}

		if(solution == true)
			cout<<"Case #"<<i<<": Yes"<<endl;
		else
			cout<<"Case #"<<i<<": No"<<endl;
	}
	return 0;
}
