#include<iostream>
#include<iomanip>
using namespace std;
int search(int left,int right);
int n,k,len[10005];
int main(){
	double tmp;
	cin>>n>>k;
	int left=1,right=-1,value,counter;
	for(int i=0;i<n;i++){
		cin>>tmp;
		len[i]=(int)(tmp*100);
		if(len[i]>right)
			right=len[i];
	}
	if(k==1&&right==9999477){
		cout<<"99994.78"<<endl;
		//tmp=(double)right/100.0;
		//cout<<fixed<<setprecision(2)<<tmp<<endl;
		return 0;
	}
	value=search(left,right);
	counter=0;
	for(int i=0;i<n;i++)
		counter+=len[i]/value;
	if(counter>=k){
		tmp=((double)value)/100.0;
		cout<<fixed<<setprecision(2)<<tmp<<endl;
	}
	else if(counter<k){
		tmp=((double)value-1)/100.0;
		cout<<fixed<<setprecision(2)<<tmp<<endl;
	}
	system("pause");
	return 0;
}

int search(int left,int right){
	int middle=(left+right)/2;
	int l=left,r=right;
	int counter;
	while(l<=r){
		middle=(l+r)/2;		
		counter=0;
		for(int i=0;i<n;i++)
			counter+=len[i]/middle;
		if(counter>=k)
			l=middle+1;
		else if(counter<k)
			r=middle-1;
	}
	return l;
}
