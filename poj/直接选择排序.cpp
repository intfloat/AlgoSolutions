//ֱ��ѡ������

#include<iostream>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i=0,num[100],len,mini,tmp;
	while(cin>>num[i])
		i++;
	len=i;
	for(i=0;i<len-1;i++){
		mini=i;
		//�������Ѱ����Сֵ 
		for(int j=i+1;j<len;j++){
			if(num[j]<num[mini])
				mini=j;
		}
		//�����Ĺ��� 
		tmp=num[mini];
		num[mini]=num[i];
		num[i]=tmp;
		//���ÿ�ν����Ľ�� 
		for(int j=0;j<len;j++)
			cout<<num[j]<<" ";
		cout<<endl;
	}
	system("pause");
	return 0;
} 
