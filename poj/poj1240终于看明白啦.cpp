//����������Сʱ�����о����Ǻ�ˬ��~ 
#include<iostream>
#include<cstring>
using namespace std;
int com(int tmpn, int m);
int hunt(int len,char *pre, char *pos);
int n;
int main(){
	int len;
	char pre[27],pos[27];
    while(cin>>n&&n){
		cin>>pre>>pos;
		len=strlen(pre);
		cout<<hunt(len,pre,pos)<<endl;        
    }
    system("pause");
    return 0;
}

int hunt(int len,char *pre, char *pos){
	int left=1,right=0,nChild=0,goal=1;
	while(left<len){
		nChild++;
		while(pre[left]!=pos[right])
			right++;
		//�������һ��ʼ���˶��ڸ��ڵ�ķ��ʣ��ʼ�һ	
		goal*=hunt(right-left+2,pre+left,pos+left-1);
		//����һ���������б��� 
		left=right+2; 
	}
	//cout<<"test: "<<n<<" "<<nChild<<" "<<com(n,nChild)<<endl;
	return goal*com(n,nChild);
}

//��������� (����������󣬽׳˵������ٶ�ʵ���ᾪ����)
int com(int tmpn, int m){
	if(m==0)
		return 1; 
	double goal,fac_n,fac_nm,i;
	goal=1;
	for(i=m;i<tmpn;i++)
		goal=goal*(i+1);
	fac_n=goal; goal=1;
	for(i=1;i<tmpn-m;i++)
		goal=goal*(i+1);
	fac_nm=goal;
	//cout<<tmpn<<" "<<m<<endl;
	//cout<<fac_n<<" "<<fac_nm<<endl;	
	goal=fac_n/fac_nm;
	return (int)goal;
}
