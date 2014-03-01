//超时了啊，真悲剧 
#include<iostream>
#include<queue>
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	queue<int> q;
	int ans[15];
	int k,n;
	bool find;
	//读入数据 
	for(int i=0;i<15;i++)
		ans[i]=-1;
	while(cin>>k&&k){
		if(ans[k]!=-1){
			cout<<ans[k]<<endl;
			break;
		}
		n=2*k;		
		for(int i=k+1;;i++){
			//if(find==true)
			//	break;
			while(q.empty()==false)
				q.pop();
			for(int j=1;j<=n;j++)
				q.push(j);
			find=true;
			for(int m=0;m<k;m++){
				for(int j=0;j<i-1;j++){
					q.push(q.front());
					q.pop();
				}
				//出现了不符合要求的情形 
				if(q.front()<=k){
					find=false;
					break;
				}
				else{
					//cout<<q.front()<<endl;
					q.pop();					
				}
				/*else if(m<k-1)
					q.pop();
				else if(m==k-1){
					cout<<i<<endl;
					break;
				}*/
			}
			if(find==true&&q.front()<=k){
				ans[k]=i;
				cout<<i<<endl;			
				break;
			}
			//if()
		}
	}
	system("pause");
	return 0;
}
