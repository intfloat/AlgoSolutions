#include<iostream>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<memory.h>
#include<string.h>

using namespace std;
char ch[10000][100];
int main(){
	
	
	//�������� 
	queue<char *> q;
	int t,i,len,count;
	bool flag,last,end=false;
	char *tmp,tem[100],tem1[100],goal[100];	
	
	
	//������������ 
	cin.getline(tem1,50,'\n');
	sscanf(tem1,"%s",tem);
	while(1){
		//�ж��Ƿ�Ӧ����ֹ���� 
		if(end==true)
			break;	
		//��ն���	
		while(q.empty()==false)	
			q.pop();
		i=0;
		//��ÿ���ַ�������г�ʼ�� 
		memset(ch[i],'\0',sizeof(ch[i]));
		//���ζ���ÿ������ 
		
		
		while(cin.getline(tem,90,'\n')){
			sscanf(tem,"%s",ch[i]);
			//������������������� 
			if(ch[i][0]=='!'&&strlen(ch[i])==1){
				end=true;
				break;
			}
			//����������������ʵĶ��� 
			if(strlen(ch[i])==0)
				break;
			q.push(ch[i]);
			i++;
			memset(ch[i],'\0',sizeof(ch[i]));			
		}		
				
		//�Դ����ҵ����ʽ��г�ʼ��	
		memset(goal,'\0',strlen(goal));
		if(end==true)
			break;
		count=0;
		//��������ҵ����� 		
		
		while(cin.getline(tem,90,'\n')){
			sscanf(tem,"%s",goal);
			
			//�����ĳ�ʼ�� 
			count=0;		
			if(strlen(goal)==0)
				break;
			flag=false; 
			len=q.size();
			
			//�Զ��н��б���Ѱ�� 
			while(len--){
				tmp=q.front();			
				if(strcmp(tmp,goal)==0&&tmp[0]!='{'&&tmp[0]!='}'){
					//�ҵ�����flag��true 
					flag=true;
					//�Ա�ʾ��εı���count���г�ʼ�� 
					count=0;
					q.push(tmp);
					q.pop();
					break;
				}
				q.push(tmp);
				q.pop();
			}
			last=true;				
			//�ָ������Խ�����һ�ֲ���	
			while(flag==true&&len--){				
				if(count>0){
					tmp=q.front();
					q.push(tmp);
					q.pop();
					continue;
				}
				tmp=q.front();
				//����'{'�򽫲�μ�һ 
				if(strlen(tmp)==1&&tmp[0]=='{'){
					count--;
					q.push(tmp); q.pop();
					continue;
				}
				//����'}'�򽫲�μ�һ 
				else if(strlen(tmp)==1&&tmp[0]=='}'){
					count++;
					q.push(tmp); q.pop();
					continue;			
				}
				//�������ͬһ����������� 
				if(count==0&&strlen(tmp)>0&&tmp[0]!='{'&&tmp[0]!='}'){
					cout<<tmp;
					q.push(tmp); q.pop();
					last=false;
				}
				//����ǲ�ͬ������������ 
				else if(count<0||count>0){
					q.push(tmp); q.pop();
					continue;
				}				
			}
			//δ�ҵ�Ŀ���ַ��������'No' 
			if(flag==false)	
				cout<<"No";
			else if(flag==true&&last==true)
				cout<<"";
			cout<<endl;		
			memset(goal,'\0',sizeof(goal));					
		}
		
		//���տ��� 
		cin.getline(tem1,10,'\n');
		sscanf(tem1,"%s",tem);		
		memset(goal,'\0',sizeof(goal));			
	}
	system("pause");
	return 0;
}
