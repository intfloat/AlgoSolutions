#include<iostream>
#include<algorithm>
using namespace std;
void search(int stickNumber,int left,bool first,int lastLength);
bool cmp(int a,int b){
	return a>b;
}
const int MAX=999999;
int n,edgeLength,length[25];
bool goal,selected[25];

int main(){
	int t,sum;
	cin>>t;
	while(t--){			
		goal=false;
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++){
			cin>>length[i];
			sum+=length[i];
		}		
		if(sum%4!=0){
			cout<<"no"<<endl;
			continue;
		}
		else edgeLength=sum/4;		
		sort(length,length+n,cmp);		
		if(length[0]>edgeLength){
			cout<<"no"<<endl;
			continue;
		}			
		search(1,edgeLength,true,MAX);			
		if(goal==true)
			cout<<"yes"<<endl;
		else cout<<"no"<<endl;		
	}
	
	return 0;
}
//正在拼的棍子编号、剩余长度、是否是新棍子 
void search(int stickNumber,int left,bool first,int lastLength){
	bool full=false;
	int fullNumber;
	//successfully search
	if(stickNumber==5||goal==true){
		goal=true;
		return;
	}
	for(int i=0;i<n;i++){
		if(length[i]==left&&selected[i]==false){
			full=true;
			fullNumber=i;
			break;
		}
	}
	//存在一根木棒可恰好填满空隙 
	if(full==true){
		selected[fullNumber]=true;	
		search(stickNumber+1,edgeLength,true,MAX);
		selected[fullNumber]=false;
		return;
	}
	for(int i=0;i<n;i++){				
		if(selected[i]==false&&length[i]<=left){
			if(length[i]>lastLength)
				continue;
			selected[i]=true;			
			search(stickNumber,left-length[i],false,length[i]);
			selected[i]=false;			
			if(goal==true||first==true)
				return;
		}
	}
	return;
}
