#include<stdio.h>
#include<cstring>
#include<string.h>
using namespace std;
int mycmp(char ch1[],char ch2[]);
int main(){
	char goal[50],tmp[50];
	int fir;
	scanf("%s",goal);
	int len=strlen(goal);
	int count=0;
	int i=0; 
	while(scanf("%s",tmp)){
		if(tmp[0]=='!')
			break; 
		if(mycmp(goal,tmp)==0){
			count++;
			if(count==1)
				fir=i;
		}
		i++;
	}
	if(count==0)
		printf("-1\n");
	else
		printf("%d %d\n",count,fir);
		//cout<<count<<" "<<fir<<endl;
	//system("pause");
	return 0;
} 

int mycmp(char ch1[],char ch2[]){
	for(int i=0;i<10;i++){
		if(ch1[i]=='\0'&&ch2[i]=='\0')
			return 0;
		if(ch1[i]!=ch2[i]&&ch1[i]-ch2[i]!=32&&ch2[i]-ch1[i]!=32)
			return -1;
	}
	return 0;
}
