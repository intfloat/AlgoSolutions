#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int totalTime,number,value[101],time[101],maxValue[1005];
	cin>>totalTime>>number;
	for(int i=0;i<1001;i++)
		maxValue[i]=0;
	for(int i=0;i<number;i++)
		cin>>time[i]>>value[i];
	for(int i=0;i<number;i++){
		for(int j=1000;j>=time[i];j--)
			maxValue[j]=max(maxValue[j],maxValue[j-time[i]]+value[i]);
	}
	cout<<maxValue[totalTime]<<endl;
	system("pause");
	return 0;
}
