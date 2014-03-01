#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=999999;

bool cmp(int a,int b){ return a>b; }
void dfs(int StickNumber,int left,int preLength);

int n,sum,goal,len[101];
int counter;
bool haveSolution,selected[101];
int main(){	
	int maxLength,maxNumber;
	while(cin>>n&&n){
		counter=0;
		maxLength=-1;
		sum=0;
		for(int i=0;i<n;i++){
			cin>>len[i];	
			sum+=len[i];
		}	
		sort(len,len+n,cmp);
		maxLength=len[0];		
		haveSolution=false;
		maxNumber=sum/maxLength;
		for(int i=maxNumber;i>1;i--){
			goal=i;
			if(sum%i!=0)
				continue;
			for(int j=0;j<n;j++)
				selected[j]=false;
			if(sum/i>maxLength&&sum/i<maxLength+len[n-1])
				continue;		
			dfs(1,sum/i,MAX);
			if(haveSolution==true){
				cout<<sum/i<<endl;
				break;
			}
		}		
		if(haveSolution==false)
			cout<<sum<<endl;
	}
	//system("pause");
	return 0;
}

void dfs(int StickNumber,int left,int preLength){
	if(haveSolution==true)
		return;
	if(StickNumber==goal+1){
		haveSolution=true;
		return;
	}
	int pre=MAX;	
	for(int i=0;i<n;i++){
		if(selected[i]==true||len[i]>left)
			continue;
		if(len[i]>preLength)
			continue;
		if(len[i]==pre)
			continue;
		selected[i]=true;
		pre=len[i];		
		if(len[i]==left)
			dfs(StickNumber+1,sum/goal,MAX);		
		else dfs(StickNumber,left-len[i],len[i]);
		selected[i]=false;
		if(left==sum/goal||len[i]==left)
			return;
		if(haveSolution==true)
			return;
	}
	return;
}
