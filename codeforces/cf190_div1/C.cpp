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
	int n, a, b;
	cout<<(-1)%1<<endl;
	string str = "";
	for(char c='Z'; c>='A'; c--){
		str += c;
		str += c;
	}
	for(char c='B'; c<='Z'; c++){
		str += c;
		str += c;
	}
	int len = str.size();
	
	vector<int> edge[100005];
	int res[100005];
	memset(res, 0, sizeof(res));
	bool solution = true;
	cin>>n;
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++){
		if(solution == false)
			break;
		if(res[i]==0 && edge[i].size()==1){
			queue<int> q;
			q.push(i);			
			int ptr = 0;
			res[i] = str[ptr];
			while(q.empty()==false){
				int si = q.size();
				ptr++;
				for(int k=0; k<si; k++){
					int tmp = q.front();
					q.pop();			
					int tlen = edge[tmp].size();
					for(int j=0; j<tlen; j++){
						if(res[edge[tmp][j]] == 0){
							if(ptr >= len){
								cout<<"Impossible!"<<endl;
								return 0;
								//break;
							}
							q.push(edge[tmp][j]);
							res[edge[tmp][j]] = str[ptr];
						}
					}
				}				
			}// end while
		}// end if
	}// end for loop
	
	if(solution == false)
		cout<<"Impossible!"<<endl;
	else{
		for(int i=1; i<=n; i++)
			cout<<(char)res[i]<<" ";
		cout<<endl;
	}
	system("pause");
	return 0;
}
