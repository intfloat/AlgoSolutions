#include<iostream>
#include<iomanip>
#define MAX 101
using namespace std;

void Multiply();
void Reverse(int m[MAX][MAX],int r,int c);

int r1,r2,c1,c2;
int matrix[MAX][MAX],matrix1[MAX][MAX],matrix2[MAX][MAX];
int main(){
	cin>>r1>>c1;
	for(int i=0;i<r1;i++)
	for(int j=0;j<c1;j++)
		cin>>matrix1[i][j];
	cin>>r2>>c2;
	for(int i=0;i<r2;i++)
	for(int j=0;j<c2;j++)
		cin>>matrix2[i][j];
	//可以进行乘法运算 
	if(c1==r2){
		Multiply();
		Reverse(matrix,r1,c2);
	}
	else
		Reverse(matrix1,r1,c1);
	system("pause");
	return 0;
}

//实现矩阵反转 
void Reverse(int m[MAX][MAX],int r,int c){
	int tmp;
	/*for(int i=0;i<r;i++)
	for(int j=0;j<i;j++){
		tmp=m[i][j];
		m[i][j]=m[j][i];
		m[j][i]=tmp;
	}*/
	for(int i=0;i<c;i++){
		for(int j=0;j<r;j++){
			cout<<setw(5)<<m[j][i];
		}
		cout<<endl;
	}
}

//实现矩阵乘法 
void Multiply(){
	int sum;
	for(int i=0;i<r1;i++)
	for(int j=0;j<c2;j++){
		sum=0;
		for(int m=0;m<c1;m++)
		//for(int n=0;n<r2;n++)
			sum+=matrix1[i][m]*matrix2[m][j];
		matrix[i][j]=sum;
	}	
}
