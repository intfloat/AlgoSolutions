#include<iostream>
using namespace std;
int main(){
	int n,sum,speed,total,cur;
	while(cin>>n&&n!=-1){
		sum=0;
		cur=0;
		while(n--){
			cin>>speed>>total;
			sum+=speed*(total-cur);
			cur=total;
		}
		cout<<sum<<" miles"<<endl;
	}
	system("pause");
	return 0;
}
