#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int main(){
	int n, res;
	vector<int> edge[205];
	bool check[205];
	//in degree for every vertex
	int degree[205];
	memset(degree, 0, sizeof(degree));
	memset(check, false, sizeof(check));
	
	cin>>n;
	for(int i=0; i<n; i++){
		int tmp;
		while(cin>>tmp && tmp){
			edge[i].push_back(tmp-1);
			degree[tmp-1]++;
		}
	}
	res = 0;
	for(int i=0; i<n; i++){
		//in degree is 0
		if(degree[i] == 0){
			queue<int> q;
			q.push(i);
			check[i] = true;
			while(q.empty() == false){
				int tmp = q.front();
				q.pop();
				int len = edge[tmp].size();
				for(int j=0; j<len; j++){
					if(check[edge[tmp][j]] == false){
						q.push(edge[tmp][j]);
						check[edge[tmp][j]] = true;
					}
				}//end for loop
			}//end while loop
			res++;
		}//end if
	}
	
	//check for cycles
	for(int i=0; i<n; i++){
		if(check[i] == false){
			queue<int> q;
			q.push(i);
			check[i] = true;
			while(q.empty() == false){
				int tmp = q.front();
				q.pop();
				int len = edge[tmp].size();
				for(int j=0; j<len; j++){
					if(check[edge[tmp][j]] == false){
						q.push(edge[tmp][j]);
						check[edge[tmp][j]] = true;
					}
				}//end for loop
			}//end while loop
			res++;
		}
	}
	cout<<res<<endl;
	system("pause");
	return 0;
}
