#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
struct Node{
	int j,wei;
};
Node tmp;
vector<Node> v[205];
queue<int> q;
int main(){
	int n,p,tmpi,active[205],u[205];
	bool fir_layer[205],next[205];
	cin>>n>>p;
	memset(fir_layer,true,n);
	for(int i=0;i<n;i++){ 
		cin>>active[i]>>u[i];
		v[i].clear();
	} 
	for(int i=0;i<p;i++){
		cin>>tmpi>>tmp.j>>tmp.wei;
		tmpi--;    tmp.j--;                                                                //下标的定义上有所差异 
		fir_layer[tmp.j]=false;
		v[tmpi].push_back(tmp);
	}
	while(q.empty()==false)
		q.pop();
	for(int i=0;i<n;i++){
		if(fir_layer[i]==true)
			q.push(i);
	}
	//cout<<"size: "<<q.size()<<endl;
	while(q.empty()==false){
		memset(next,false,n);
	//	cout<<"size: "<<q.size()<<endl;
		int tmp_len=q.size();
		for(int i=0;i<tmp_len;i++){
			int ele=q.front();
			q.pop();
			if(active[i]<=0)
				continue;
			int len=v[ele].size();
			//cout<<"len: "<<len<<endl;
			for(int j=0;j<len;j++){
				Node t=v[ele][j];
				active[t.j]+=active[i]*t.wei;
				next[t.j]=true;
			}		
		}
		for(int i=0;i<n;i++){
			if(next[i]==true){
				active[i]-=u[i];
				q.push(i);
			}
			//cout<<"size: "<<q.size()<<endl;
		}//end for loop
	}
	bool output_empty=true;
	for(int i=0;i<n;i++){
		if(v[i].size()==0&&active[i]>0){
			output_empty=false;
			cout<<i+1<<" "<<active[i]<<endl;
		}
		//cout<<"size: "<<v[i].size()<<endl;
	}
	if(output_empty==true)
		cout<<"NULL"<<endl;
	system("pause");
	return 0;
}
