/*
�Կո���Ϊʯ����Ŀ�����Խ�ʯ�ӷŵ��ұߵ�����λ��
Ҳ���Խ����ұߵ�ʯ���ӵ���
ż��λ�õ�ʯ���൱�ڱ��ӵ������ڽ�ֵ�ʤ�ܺ������á� 
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t,n,sum,position[10005];
	cin>>t;
	while(t--){
		cin>>n;
		position[0]=0;
		for(int i=1;i<=n;i++)
			cin>>position[i];
		sort(position,position+n+1);
		sum=0;
		for(int i=n;i>0;i-=2){
			sum=sum^(position[i]-position[i-1]-1);
		}
		if(sum==0)
			cout<<"Bob will win"<<endl;
		else cout<<"Georgia will win"<<endl;
	}
	system("pause");
	return 0;
} 
