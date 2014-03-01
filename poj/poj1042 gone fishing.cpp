#include<iostream>
using namespace std;
int main(){
	int n,hour,fiveMinutes,fish[30],dec[30],spend[30];
	int tmpTime,maximum,fishNumber,current,tmp[30],tmpgoal[30];
	int goal[30],lakeNumber;
	while(cin>>n&&n){
		cin>>hour;
		fiveMinutes=hour*12;
		for(int i=0;i<n;i++)
			cin>>fish[i];					
		for(int i=0;i<n;i++)
			cin>>dec[i];
		for(int i=0;i<n-1;i++)
			cin>>spend[i];
		maximum=-1;
		for(int i=0;i<n;i++)
			goal[i]=0;
			
			
		for(int i=0;i<n;i++){
			tmpTime=fiveMinutes;
			for(int j=0;j<n;j++){
				tmp[j]=fish[j];
				tmpgoal[j]=0;
			}
			current=0;
			for(int k=0;k<i;k++)
				tmpTime-=spend[k];
			while(tmpTime>0){
				tmpTime--;
				fishNumber=-1;
				for(int k=0;k<=i;k++){
					if(tmp[k]>fishNumber){
						fishNumber=tmp[k];
						lakeNumber=k;
					}
					if(tmp[k]<0)
						tmp[k]=0;
				}
				current+=fishNumber;
				tmp[lakeNumber]-=dec[lakeNumber];
				tmpgoal[lakeNumber]++;
				if(tmp[lakeNumber]<0)
					tmp[lakeNumber]=0;
			}
			if(current>maximum){
				maximum=current;
				for(int k=0;k<n;k++)
					goal[k]=tmpgoal[k];
			}
		}//end for loop
		
		for(int k=0;k<n-1;k++)
			cout<<goal[k]*5<<", ";
		cout<<goal[n-1]*5<<endl;
		cout<<"Number of fish expected: "<<maximum<<endl;
		cout<<endl;
		
	}
	system("pause");
	return 0;
}
