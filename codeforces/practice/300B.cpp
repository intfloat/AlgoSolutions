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
	// Build a graph
	bool g[50][50];
	vector<int> res[50];
	memset(g, false, sizeof(g));
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		a--; b--;
		g[a][b]=true; g[b][a]=true;
	}
	// Floyd algorithm
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	for(int k=0; k<n; k++){
		if(g[j][i]==true && g[i][k]==true)
			g[j][k]=true;
	}
	int ptr = 0;
	bool check[50];
	memset(check, false, sizeof(check));
	for(int i=0; i<n; i++){
		bool used = false;
		// Already checked before
		if(check[i]==true)
			continue;
		for(int j=0; j<n; j++){
			// Stay together
			if(g[i][j]==true && check[j]==false && i!=j){
				check[j] = true;
				res[ptr].push_back(j);
				used = true;
			}
		}
		if(used == true){
			res[ptr].push_back(i);
			check[i]=true;
			ptr++;			
		}
	}
	int cur = 0;
	bool hasSolution = true;
	for(int i=0; i<n/3; i++){
		if(res[i].size() > 3){
			hasSolution=false;
			break;
		}
		for(int j=cur; j<n; j++){
			if(res[i].size()==3)
				break;
			if(check[j]==false){
				//cur++;
				check[j] = true;
				res[i].push_back(j);
			}
			cur++;
		}
	}
	for(int i=0; i<n/3; i++){
		if(res[i].size()<3)
			hasSolution = false;
	}
	if(hasSolution == false)
		cout<<-1<<endl;
	else{
		for(int i=0; i<n/3; i++){
			for(int j=0; j<3; j++)
				cout<<res[i][j]+1<<" ";
			cout<<endl;
		}
	}
	//system("pause");
	return 0;
}
