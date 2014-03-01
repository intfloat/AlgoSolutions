#include<iostream>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<memory.h>
#include<string.h>

using namespace std;
char ch[10000][100];
int main(){
	
	
	//变量定义 
	queue<char *> q;
	int t,i,len,count;
	bool flag,last,end=false;
	char *tmp,tem[100],tem1[100],goal[100];	
	
	
	//读入数据组数 
	cin.getline(tem1,50,'\n');
	sscanf(tem1,"%s",tem);
	while(1){
		//判断是否应该终止程序 
		if(end==true)
			break;	
		//清空队列	
		while(q.empty()==false)	
			q.pop();
		i=0;
		//对每个字符数组进行初始化 
		memset(ch[i],'\0',sizeof(ch[i]));
		//依次读入每组数据 
		
		
		while(cin.getline(tem,90,'\n')){
			sscanf(tem,"%s",ch[i]);
			//遇到‘！’则结束程序 
			if(ch[i][0]=='!'&&strlen(ch[i])==1){
				end=true;
				break;
			}
			//遇到空行则结束物质的读入 
			if(strlen(ch[i])==0)
				break;
			q.push(ch[i]);
			i++;
			memset(ch[i],'\0',sizeof(ch[i]));			
		}		
				
		//对待查找的物质进行初始化	
		memset(goal,'\0',strlen(goal));
		if(end==true)
			break;
		count=0;
		//读入待查找的物质 		
		
		while(cin.getline(tem,90,'\n')){
			sscanf(tem,"%s",goal);
			
			//变量的初始化 
			count=0;		
			if(strlen(goal)==0)
				break;
			flag=false; 
			len=q.size();
			
			//对队列进行遍历寻找 
			while(len--){
				tmp=q.front();			
				if(strcmp(tmp,goal)==0&&tmp[0]!='{'&&tmp[0]!='}'){
					//找到了则将flag置true 
					flag=true;
					//对表示层次的变量count进行初始化 
					count=0;
					q.push(tmp);
					q.pop();
					break;
				}
				q.push(tmp);
				q.pop();
			}
			last=true;				
			//恢复队列以进行下一轮查找	
			while(flag==true&&len--){				
				if(count>0){
					tmp=q.front();
					q.push(tmp);
					q.pop();
					continue;
				}
				tmp=q.front();
				//遇到'{'则将层次减一 
				if(strlen(tmp)==1&&tmp[0]=='{'){
					count--;
					q.push(tmp); q.pop();
					continue;
				}
				//遇到'}'则将层次加一 
				else if(strlen(tmp)==1&&tmp[0]=='}'){
					count++;
					q.push(tmp); q.pop();
					continue;			
				}
				//如果是在同一层次则输出结果 
				if(count==0&&strlen(tmp)>0&&tmp[0]!='{'&&tmp[0]!='}'){
					cout<<tmp;
					q.push(tmp); q.pop();
					last=false;
				}
				//如果是不同层次则继续查找 
				else if(count<0||count>0){
					q.push(tmp); q.pop();
					continue;
				}				
			}
			//未找到目标字符串则输出'No' 
			if(flag==false)	
				cout<<"No";
			else if(flag==true&&last==true)
				cout<<"";
			cout<<endl;		
			memset(goal,'\0',sizeof(goal));					
		}
		
		//吸收空行 
		cin.getline(tem1,10,'\n');
		sscanf(tem1,"%s",tem);		
		memset(goal,'\0',sizeof(goal));			
	}
	system("pause");
	return 0;
}
