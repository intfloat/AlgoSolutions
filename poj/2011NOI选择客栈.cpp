//Ñ¡Ôñ¿ÍÕ»
#include<iostream>
#include<stdio.h>
#include<algorithm> 
using namespace std;
const int MAX=20005;
int main(){
	int n,color_number,cost,sum,last;
	int left_number,right_number;
	int color_counter[MAX],price[MAX],color[MAX];
	bool flag;
	scanf("%d%d%d",&n,&color_number,&cost);
	//cin>>n>>color_number>>cost;
	for(int i=0;i<n;i++)
		scanf("%d%d",&color[i],&price[i]);
		//cin>>color[i]>>price[i];
	sum=0;
	for(int i=0;i<color_number;i++){
		if(color[0]==i)
			color_counter[0]=1;
		else color_counter[0]=0;
		
		for(int j=1;j<n;j++){
			if(color[j]==i)
				color_counter[j]=color_counter[j-1]+1;
			else color_counter[j]=color_counter[j-1];
		}
		
		last=0; flag=false;
		for(int j=0;j<n;j++){
			if(price[j]<=cost){				
				if(color[j]==i)
					left_number=max(color_counter[j]-color_counter[last]-1,0);				
				else left_number=color_counter[j]-color_counter[last];
				right_number=color_counter[n-1]-color_counter[j];
				//if(color[j]!=i)
				sum+=left_number*right_number;
				if(last==0&&color[0]==i&&flag==false){
					if(j==0){
						sum+=right_number;
						flag=true;
						continue;
					}
					if(color[j]==i)
						sum+=right_number+1;
					else sum+=right_number;
					flag=true;
				}
				if(color[j]==i)
					sum+=left_number+right_number;
				last=j;
			}//end if
		}//end for loop
		//cout<<i<<": "<<sum<<endl;
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
} 
