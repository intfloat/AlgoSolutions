//����Ĵ���

#include<iostream>
#include<stdlib.h>
#define MAX 9999999
using namespace std;
//�ýڵ�����¼�õ��Ƿ񱻷����Լ�ԭ����λ��
struct Node{
	//������ 
	int original;
	//δ����ʱ��λ������ 
	int x;
	//�Ƿ��Ѿ�������������Ϊ 
	bool visited; 
};
Node node[1000];
int n,num[1000];

//Ѱ����һ��λ�õ�Ԫ�� 
int find(int tem);
//��������ıȽϺ��� 
int cmp(const void *elem1,const void *elem2){
	Node *p=(Node *)elem1,*q=(Node *)elem2;
	return (p->original)-(q->original);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int j,t,goal,tmp_mini,mini,sum,begin,count,min1,min2;
	
	while(cin>>t&&t){
		n=t;		
		mini=MAX; goal=0;
		//�������ݲ����б�Ҫ�ĳ�ʼ������ 
		for(int i=0;i<t;i++){
			cin>>node[i].original;	
			num[i]=node[i].original;
			node[i].x=i;		
			//���Ϊδ����			
			node[i].visited=false;
			//Ѱ����Сֵ 
			if(node[i].original<mini)
				mini=node[i].original;
		}
		//�ÿ�����ȷ��Ԫ���ź����ô���λ��		
		qsort(node,t,sizeof(Node),cmp);
		for(int i=0;i<t;i++){
			//node[i].x��ʾԭ�ȵ�λ�ã�i���ʾӦ�ô���λ�� 
			tmp_mini=node[i].original; begin=node[i].x;	
			j=i; count=1;
			//��ʼ���ۼ���		
			sum=node[i].original; 
			if(node[i].visited==false){
				node[i].visited=true;
				//iָʾ��ǰԪ��Ӧ�ô���λ�� 
				while(j!=begin){
					//Ѱ����һ������λ�� 					
					j=find(num[j]);	
					//��Ԫ���ܺͲ���Ԫ�ظ������м��� 
					sum+=node[j].original;
					count++;
					//Ѱ����ʱ��Сֵ 
					if(node[j].original<tmp_mini)
						tmp_mini=node[j].original;
					node[j].visited=true;				
				}
			}
			//�������ڵ���С���� 
			min1=sum+(count-2)*tmp_mini;
			//������Сֵ�󽻻��Ĵ��� 
			min2=sum+(count+1)*mini+tmp_mini;			
			//ȡ���������е�С�߼ӵ��ܵĴ����� 
			if(min1<min2)
				goal+=min1;
			else goal+=min2;
		}
		//������ս�� 
		cout<<goal<<endl;
	}
	return 0;
}

//Ѱ����һ��λ�� 
int find(int tem){
	for(int i=0;i<n;i++){
		//����Ԫ�ػ�����ͬ���ҵ�һ����Ŀ��ؼ�ֵ��ͬ�Ľ�㼴���ؽ�� 
		if(node[i].original==tem)
			return i;
	}
	return 0;
}
