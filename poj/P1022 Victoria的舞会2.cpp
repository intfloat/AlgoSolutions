/*
P1022 Victoria的舞会2
本质上是求一个图中有多少个强连通分支，
邻接矩阵求n次方，然后从中照强连通分支即可 
*/
#include<iostream> 
#include<algorithm>
using namespace std;

struct MATRIX{
	int matrix[201][201];
};
MATRIX matrix_power(MATRIX ma,int p); 
MATRIX matrix_multiply(MATRIX ma1,MATRIX ma2); 
int main(){
	int n;
	MATRIX ma,goal;
	memset(ma.matrix,0,sizeof(ma.matrix));
	cin>>n;
	for(int i=1;i<=n;i++){
		int tmp;
		while(cin>>tmp && tmp){
			ma.matrix[i][tmp]=1;
		}
	}
	goal=matrix_power(ma,n);
	
	int counter=0;
	bool checked[205];
	memset(checked,false,sizeof(checked));
	for(int i=1;i<=n;i++){
		if(checked[i]==true)
			continue;
		counter++;
		checked[i]=true;
		for(int j=1;j<=n;j++){
			if((goal.matrix[i][j]>0) 
				&& (checked[j]==false)
				&& (goal.matrix[j][i]>0)){
				checked[j]=true;
			}
		}
	}
	cout<<counter<<endl;
	system("pause");
	return 0;
}

MATRIX matrix_power(MATRIX ma,int p){
	if(p==1)
		return ma;
	MATRIX tmp=matrix_power(ma,p/2);
	tmp=matrix_multiply(tmp,tmp);
	if(p%2==1)
		tmp=matrix_multiply(tmp,ma);
	return tmp;
}

MATRIX matrix_multiply(MATRIX ma1,MATRIX ma2){
	MATRIX result;
	/*
	尚未完成 
	*/
	return result;
}
