//木有看清题意啊......真悲剧 
#include<ctime>
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
struct Node{
	char ch[4][81];
};
Node node[101];
int main(){
	char tmp[81];
	char *ptr;
	int i,j,count=0;
	for(i=0;i<101;i++)
	for(j=0;j<4;j++)	
		node[i].ch[j][0]='\0';
	while(cin.getline(tmp,80)){
		if(strcmp(tmp,"end")==0)
			break;
		if(tmp[0]!='['){
			cout<<tmp<<endl;
			while(cin.getline(tmp,80)&&strlen(tmp)!=0){
					cout<<tmp<<endl;
			}
			cout<<endl;
			continue;
		}
		strcpy(node[count].ch[0],tmp);
		i=1;
		while(i<=3){
			cin.getline(node[count].ch[i],80);
			//cin>>node[count].ch[i];
			if(strlen(node[count].ch[i])==0)
				break;
			i++;
		}
		count++;
	}
	for(i=0;i<count;i++){
		cout<<"["<<i+1<<"]";
		j=0;
		while(node[i].ch[0][j]!=']')
			j++;
		ptr=&node[i].ch[0][j+1];
		cout<<ptr<<endl;
		for(int j=1;j<3;j++){
			if(node[i].ch[j][0]!='\0')
				cout<<node[i].ch[j]<<endl;
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
