#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num,sec;
	while(scanf("%d%d",&num,&sec)!=EOF){
		char str[100];
		scanf(" %s",str);
		for(int i=0;i<sec;i++)
		for(int i=1;i<num;i++){
				if(str[i-1]=='B' && str[i]=='G'){
					str[i-1]='G';
					str[i]='B';
					i++;
				}
		}
		printf("%s\n",str);
	}
//	printf("%s\n",str);
	system("pause");
	return 0;
}
