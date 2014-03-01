#include<iostream>
using namespace std;

struct MATRIX{
	long long matrix[115][115];
};
MATRIX ma;
MATRIX matrix_mul(MATRIX a,MATRIX b);
MATRIX matrix_mi(MATRIX ma,long long p);
long long n,m,k;

int main(){
	//int peanut[105];
	long long tmp;
	int number,number1,number2;
	char command;
	bool output=false;
	while(cin>>n>>m>>k){
		if(n==0&&m==0&&k==0)
			break;
		output=false;
		for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			ma.matrix[i][j]=0;
		for(int i=0;i<=n;i++){
			ma.matrix[i][i]=1;
			//peanut[i]=0;
		}
		//peanut[n]=1;
		
		for(int i=0;i<k;i++){
			cin>>command;
			if(command=='g'){
				cin>>number;
				ma.matrix[n][number-1]++;
			}
			else if(command=='e'){
				cin>>number;
				for(int j=0;j<=n;j++)
					ma.matrix[j][number-1]=0;
				//cout<<"command"<<endl;					
			}
			else{
				cin>>number1>>number2;
				number1--; number2--;			
				for(int j=0;j<=n;j++){
					tmp=ma.matrix[j][number1];
					ma.matrix[j][number1]=ma.matrix[j][number2];
					ma.matrix[j][number2]=tmp;
				}
				//cout<<"end exchange"<<endl;
			}//end if
		}//end for loop
		//cout<<"here"<<endl;
		if(m!=0)
			ma=matrix_mi(ma,m);
		cout<<ma.matrix[n][0];
		output=true;
		for(int i=1;i<n;i++)
			cout<<" "<<ma.matrix[n][i];
		cout<<" ";
		cout<<endl;		
	}
	if(output==false)
		cout<<"what happened?"<<endl;
	
	return 0;
}
//交换一下乘法顺序，可以大大加快运算过程 
MATRIX matrix_mul(MATRIX a,MATRIX b){
	MATRIX tmp;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
		tmp.matrix[i][j]=0;
	//cout<<"multiplication"<<endl;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++){
		if(a.matrix[i][j]!=0){
		for(int co=0;co<=n;co++){
			tmp.matrix[i][co]+=a.matrix[i][j]*b.matrix[j][co];
		}}
	}
	return tmp;
}


MATRIX matrix_mi(MATRIX ma,long long p){
	MATRIX tmp;
	if(p==1)
		return ma;	
	tmp=matrix_mi(ma,p/2);
	tmp=matrix_mul(tmp,tmp);
	if(p%2==1)
		tmp=matrix_mul(tmp,ma);
	return tmp;
} 
