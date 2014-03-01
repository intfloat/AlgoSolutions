#include<iostream>
#include<cstring>
//#define max(a,b)  (a>b)?a:b
using namespace std;
//int common(int len1,int len2);

int main(){	
	char str1[2000],str2[2000];
	int common[500][500];
	int len1,len2;
	while(cin>>str1>>str2){
		len1=strlen(str1);
		len2=strlen(str2);
		for(int i=0;i<len1;i++){
			common[0][i]=0;
			common[i][0]=0;
		}
		for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++){
			if(str1[i-1]==str2[j-1])
				common[i][j]=common[i-1][j-1]+1;
			else if(common[i-1][j]>common[i][j-1])
				common[i][j]=common[i-1][j];
			else
				common[i][j]=common[i][j-1];
		}
		cout<<common[len1][len2]<<endl;
	}
	system("pause");
	return 0;
} 

/*int common(int len1,int len2){
	if(len1==0||len2==0)
		return 0;
	if(str1[len1-1]==str2[len2-1])
		return common(len1-1,len2-1)+1;
	else
		return max(common(len1-1,len2),common(len1,len2-1));
}*/
