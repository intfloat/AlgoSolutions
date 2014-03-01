#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("out.txt","w",stdout);
	int number[10];
	for(int i=0;i<4;i++)
		number[i]=i+1;
	do{
		for(int i=0;i<4;i++)
			cout<<number[i]<<" ";
		cout<<endl;
	}while(next_permutation(number,number+4));
	return 0;
}

