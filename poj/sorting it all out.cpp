#include<iostream>
using namespace std;

int output(int n);
int Initial(int n);
bool Complete(int n);
int Floyd(int n);

int path[30],dis[30][30];

int main(){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int n,m;
	char ch1,ch2,tmp;	
	bool find,sorted;
	
	while(cin>>n>>m&&n&&m){
		Initial(n);
		find=true; sorted=false;
		for(int i=0;i<m;i++){
			cin>>ch1>>tmp>>ch2;	
			//和现有情形产生矛盾	
			if(find==true&&dis[ch2-'A'][ch1-'A']>0){
				find=false;
				cout<<"Inconsistency found after "<<i+1<<" relations."<<endl;
			}
			else if(find==true&&sorted==false){
				dis[ch1-'A'][ch2-'A']=1;				
				Floyd(n);
				if(Complete(n)==true){
					sorted=true; find=false;
					cout<<"Sorted sequence determined after "<<i+1<<" relations: ";
					output(n);
					cout<<"."<<endl;
				}
			}
		}
		if(find==true&&sorted==false)
			cout<<"Sorted sequence cannot be determined."<<endl;
	}
	return 0;
}

int output(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(path[j]==i)
				cout<<(char)('A'+j);		
	}
	return 0;
}

bool Complete(int n){
	bool tmp;
	for(int i=0;i<n;i++){
		tmp=false;
		for(int j=0;j<n;j++)
			if(path[j]==i)
				tmp=true;		
		if(tmp==false)
			return false;
	}
	return true;
}

int Initial(int n){	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		dis[i][j]=-1;
	for(int i=0;i<n;i++)
		path[i]=0;
	return 0;
}

int Floyd(int n){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	for(int k=0;k<n;k++)
		if(dis[j][i]>0&&dis[i][k]>0)
			dis[j][k]=1;
	//重复k次才能保证路径无遗漏 
	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		if(dis[i][j]>0&&path[j]<path[i]+1)
			path[j]=path[i]+1;
	return 0;
}
