#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int t,m,n,tmp,count,position;
	bool visited[100];
	char ch[100];
	int num[100],goal[100];
	cin>>t;
	while(t--){
		cin>>n; position=0; m=0;
		for(int i=0;i<n;i++){
			//visited[i]=false;
			cin>>num[i];
			if(i==0) tmp=num[0];
			else tmp=num[i]-num[i-1];
			while(tmp--)
				ch[position++]='(';
			ch[position++]=')';
		}
		//cout<<endl;
		for(int j=0;j<position;j++)
			visited[j]=false;
		//cout<<endl;
		for(int j=0;j<position;j++){
			//cout<<"position "<<position<<endl;
			count=1;
			if(ch[j]==')'){
				//cout<<"j: "<<j<<endl;
				visited[j]=true;
				for(int k=j-1;k>=0;k--){
					if(visited[k]==true&&ch[k]==')'){
						count++;
						//cout<<"test: "<<count<<endl;
					}
					if(visited[k]==false&&ch[k]=='('){
						//cout<<"test!!! "<<k<<endl;
						visited[k]=true;
						break;
					}
				}
				goal[m++]=count;
			}
		}
		for(int i=0;i<n-1;i++)
			cout<<goal[i]<<" ";
		cout<<goal[n-1]<<endl;
	}
	system("pause");
	return 0;
}
