#include<stdio.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
int cmp(const void* elem1,const void* elem2){
	char *ptr1=(char *)elem1,*ptr2=(char *)elem2;
	return strcmp(ptr1,ptr2);
}
bool pre(int i);
char str[15000][15];
int main(){
	bool Unique;
	int t,n;
	scanf("%d",&t);
	while(t--){
		Unique=true;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%s",str[i]);
		qsort(str,n,15,cmp);
		for(int i=0;i<n-1;i++){
			if(pre(i)==true){
				Unique=false;
				break;
			}
		}
		if(Unique==true)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

bool pre(int i){
	int len=strlen(str[i]);
	for(int j=0;j<len;j++){
		if(str[i][j]!=str[i+1][j])
			return false;
	}
	return true;
}
