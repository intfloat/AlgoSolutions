#include<iostream>
#include<stdio.h>
using namespace std;
struct Bug{
	int pre;
	int rank;
};
Bug bug[2005];
int find(int tmp);
int main(){
	int t,a,b,x,y,bug_num,order_num;
	bool flag;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&t);
	int count=0;
	while(t--){
		scanf("%d%d",&bug_num,&order_num);
		printf("Scenario #%d:\n",++count);
		for(int i=0;i<=bug_num;i++){
			bug[i].pre=-1;
			bug[i].rank=0;
		}
		flag=false;
		for(int i=0;i<order_num;i++){
			scanf("%d%d",&x,&y);
			if(flag==true)
				continue;
			a=find(x);
			b=find(y);
			//˵��������ͬһ���ȼ����� 
			if(a==b&&bug[x].rank==bug[y].rank)			
				flag=true;
			//��Ҫ�ϲ������ȼ��� 
			else if(a!=b){
				bug[a].pre=b;
				bug[a].rank=(bug[x].rank+bug[y].rank+1)%2;
			}
		}
		if(flag==true)
			printf("Suspicious bugs found!\n\n");
		else if(flag==false)
			printf("No suspicious bugs found!\n\n");
	}
	//system("pause");
	return 0;
}

int find(int tmp){
	int t=bug[tmp].pre;
	//�ҵ��ȼ���ĸ� 
	if(t<0)
		return tmp;
	bug[tmp].pre=find(t);
	bug[tmp].rank=(bug[t].rank+bug[tmp].rank)%2;
	return bug[tmp].pre;
}
