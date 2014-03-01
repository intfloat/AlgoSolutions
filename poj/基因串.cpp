#include<iostream>
#include<cstring>
using namespace std;

const int MAX=999;
int n,len;
int sourceAble[27][27];

	

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	bool sequenceAble[101][101][27];
	int number1,number2,goal;
	int transform[27][27];
	bool tmp1,tmp2;
	char tmp[5],geneString[150];	
	for(int i=0;i<27;i++)
	for(int j=0;j<27;j++)
		transform[i][j]=-1;	
	cin>>n;	
	for(int i=0;i<n;i++){
		cin>>tmp;
		number1=tmp[1]-'A';
		number2=tmp[2]-'A';
		goal=tmp[0]-'A';
		//表征字母之间的合并关系 
		transform[number1][number2]=goal;
		transform[number2][number1]=goal;
	}
	cin>>geneString;
	len=strlen(geneString);
	for(int i=0;i<=len;i++)
	for(int j=0;j<=len;j++)
	for(int k=0;k<=26;k++){
		//从i到j的子段能否导出k 
		sequenceAble[i][j][k]=false;
	}
	for(int i=0;i<len;i++){
		sequenceAble[i][i][(int)(geneString[i]-'A')]=true;
	}
	for(int i=2;i<=len;i++){
	for(int j=0;j<=len-i;j++){
		for(int k=j;k<i+j-1;k++){
			for(int p=0;p<26;p++){
				tmp1=sequenceAble[j][k][p];
				if(tmp1==false)
					continue;
				for(int m=0;m<26;m++){					
					tmp2=sequenceAble[k+1][i+j-1][m];
					if(tmp2==false)
						continue;
					if(transform[p][m]==-1)
						continue;
					sequenceAble[j][i+j-1][transform[p][m]]=true;
					//if(i==6&&j==0&&transform[p][m]=='S'-'A')
					//	cout<<"right!"<<endl;
					/*if(j==0&&(i+j-1)==5&&sequenceAble[0][5][18]==true){
						cout<<"nima!!"<<endl;					
						cout<<(char)(transform[p][m]+'A')<<endl;
						sequenceAble[0][5][18]=true;
					}*/
				}
			}
		}
	}}	
	for(int i=0;i<len;i++)
	for(int j=0;j<len;j++){		
		sourceAble[i][j]=MAX;
	}	
	for(int i=0;i<len;i++){
	for(int j=0;j<len;j++){
		//j代表开始位置 		
		if((sequenceAble[i][j][18])==true){
			sourceAble[i][j]=1;
			//cout<<i<<" "<<j<<endl;
		}		
	}}
	for(int i=1;i<=len;i++)
	for(int j=0;j<=len-i;j++)
	for(int k=j;k<i+j-1;k++){
		if(sourceAble[j][k]+sourceAble[k+1][i+j-1]<sourceAble[j][i+j-1])
			sourceAble[j][i+j-1]=sourceAble[j][k]+sourceAble[k+1][i+j-1];
	}	
	if(sourceAble[0][len-1]==MAX)
		cout<<-1<<endl;
	else cout<<sourceAble[0][len-1]<<endl;	
	return 0;
}
