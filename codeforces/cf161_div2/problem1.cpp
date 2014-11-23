 #include<iostream>
 #include<string>
 #include<string.h>
 #include<algorithm>
 #include<cmath>
 
 using namespace std;
 
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int matrix[10][10];
	int result=0;
	
	for(int i=1;i<=5;i++)
	for(int j=1;j<=5;j++){
		cin>>matrix[i][j];
		if(matrix[i][j]==1){
			result+=abs(i-3)+abs(j-3);
		}
	}
	cout<<result<<endl;
	return 0;
}
