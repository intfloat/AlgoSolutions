#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,stones[1005];
	while(scanf("%d",&n)&&n){
		int tmp=0;
		for(int i=0;i<n;i++){
			scanf("%d",&stones[i]);
			//cin>>stones[i];
			tmp=tmp^stones[i];
		}
		if(tmp==0){
			printf("0\n");
			//cout<<0<<endl;
			continue;
		}
		int count=0;
		for(int i=0;i<n;i++){
			if((tmp^stones[i])<stones[i])
				count++;
		}
		printf("%d\n",count);
		//cout<<count<<endl;
	}
	system("pause");
	return 0;
}
