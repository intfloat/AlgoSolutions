//纠结了两个小时啊，感觉还是很爽的~ 
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
		//后序遍历一开始少了对于根节点的访问，故减一	
		goal*=hunt(right-left+2,pre+left,pos+left-1);
		//对下一棵子树进行遍历 
		left=right+2; 
	}
	//cout<<"test: "<<n<<" "<<nChild<<" "<<com(n,nChild)<<endl;
	return goal*com(n,nChild);
}

//计算组合数 (存在溢出现象，阶乘的增长速度实在提惊人了)
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
