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


bool flag[20];
vector<int> choice[20];
int multiple = 3;
int n, k, relation[16][16];
int res = 0;
int ans[20];
void dfs(int index);

int main(){
	//freopen("assign.in", "r", stdin);
	//freopen("assign.out", "w", stdout);

	memset(ans, 0, sizeof(ans));
	memset(relation, 0, sizeof(relation));
	for(int i=0; i<16; i++)
		relation[i][i] = 1;
	cin>>n>>k;
	for(int i=0; i<k; i++){
		int x, y;
		char str;
		cin>>str>>x>>y;
		x--; y--;
		if(str == 'S'){
			relation[x][y] = 1;
			relation[y][x] = 1;
		}
		else if(str == 'D'){
			relation[x][y] = -1;
			relation[y][x] = -1;
		}
	}
	//update status
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	for(int k=0; k<n; k++){
		if(relation[j][i] == 1 && relation[i][k] == 1){
			if(relation[j][k] == -1){
				cout<<0<<endl;
				return 0;
			}
			else relation[j][k] = 1;
		}
		// I forgot these two relaations ><
		if(relation[j][i]==1 && relation[i][k]==-1){
			if(relation[j][k]==1){
				cout<<0<<endl;
				return 0;
			}
			else relation[j][k] = -1;
		}
		if(relation[j][i]==-1 && relation[i][k]==1){
			if(relation[j][k]==1){
				cout<<0<<endl;
				return 0;
			}
			else relation[j][k] = -1;
		}
	}
	
	
	memset(flag, true, sizeof(flag));
	flag[0] = false;
	for(int i=1; i<n; i++){
		if(relation[0][i] == -1){
			choice[i].push_back(1);
			choice[i].push_back(2);
		}
		else if(relation[0][i] == 1)
			flag[i] = false;
		else{
			choice[i].push_back(0);
			choice[i].push_back(1);
			choice[i].push_back(2);
		}
	}
	for(int i=0; i<n; i++){
		if(flag[i] == false)
			continue;
		flag[i] = false;
		for(int k=0; k<n; k++){
			if((i!=k) && (relation[i][k]!=0))
				flag[i] = true;
		}
		if(flag[i] == false)
			multiple = multiple*3;
	}	
	//cout<<"multiple: "<<multiple<<endl;
	dfs(0);
	res = res*multiple;
	cout<<res<<endl;
	system("pause");
	return 0;
}

void dfs(int index){
	if(index >= n){
		res++;
		return;
	}
	if(flag[index] == false){
		dfs(index+1);
		return;
	}
	int len = choice[index].size();
	for(int i=0; i<len; i++){
		ans[index] = choice[index][i];
		bool check = true;
		for(int j=0; j<index; j++){
			if(flag[j] == false)
				continue;
			if(relation[index][j]==1 && ans[index]!=ans[j]){
				check = false;
				break;
			}
			else if(relation[index][j]==-1 && ans[index]==ans[j]){
				check = false;
				break;
			}
		}//end for loop
		if(check == true){
			dfs(index+1);
		}
	}
	return;
}
