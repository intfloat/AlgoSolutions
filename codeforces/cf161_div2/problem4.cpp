#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
 
using namespace std;
void dfs(int step,int cur);

bool find_solution;
vector<int> v[100005];
vector<int> result;
int n,m,k;
int x,y;
bool check[100005];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
		
	find_solution=false;
	memset(check,false,sizeof(check));
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	for(int i=0;i<=k+100;i++)
		result.push_back(0);
	
	for(int i=1;i<=n;i++){
		if(find_solution==true)
			break;
		check[i]=true;
		result[0]=i;
		dfs(1,i);
		check[i]=false;
		if(i==n && find_solution==false){
			k++;
			i=0;
		}
	}
	/*
	int ori_len=v[1].size();
	result.push_back(1);
	check[1]=true;
	for(int i=0;i<k;i++){
		int tmp=result[i];
		int len=v[tmp].size();
		for(int j=0;j<len;j++){
			if(check[v[tmp][j]]==false && i!=(k-1)){
				result.push_back(v[tmp][j]);
				check[v[tmp][j]]=true;
				break;
			}
			else if(check[v[tmp][j]]==false && i==(k-1)){				
				for(int k=0;k<ori_len;k++){
					if(v[1][k]==tmp){
						result.push_back(v[tmp][j]);
						check[v[tmp][j]]=true;
						break;
					}
				}//end for loop
			}//end else if
		}//end for
	}
	*/
	cout<<k+1<<endl;	
	for(int i=0;i<k;i++){
		cout<<result[i]<<" ";
	}
	cout<<result[k]<<endl;
	return 0;
}

void dfs(int step,int cur){
	if(find_solution==true || step>k){
		find_solution=true;
		return;
	}
	//cout<<step<<" "<<cur<<endl;
	int len=v[cur].size();
	for(int i=0;i<len;i++){
		int tmp=v[cur][i];
		if(check[tmp]==false && step!=k){
			check[tmp]=true;
			result[step]=tmp;
			dfs(step+1,tmp);
			check[tmp]=false;
		}
		else if(check[tmp]==false && step==k){
			int ori_len=v[result[0]].size();
			for(int j=0;j<ori_len;j++){
				if(v[result[0]][j]==tmp){
					check[tmp]=true;
					result[step]=tmp;
					dfs(step+1,tmp);
					check[tmp]=false;
					break;
				}
			}
		}
		if(find_solution==true)
			return;
	}
	return;
}
