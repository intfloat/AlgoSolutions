#include<iostream>
#include<algorithm>
using namespace std;
struct Point{
	int x,y;
};
Point point[1001];
int main(){
	int n,a,b,counter,maximum;
	while(cin>>n&&n){
		maximum=-1;
		for(int i=0;i<n;i++)
			cin>>point[i].x>>point[i].y;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				counter=0;
				a=point[i].x-point[j].x;
				b=point[i].y-point[j].y;
				for(int k=j+1;k<n;k++){
					if((point[k].x-point[i].x)*b==(point[k].y-point[i].y)*a)
						counter++;
				}			
				maximum=max(maximum,counter);
			}
		}
		cout<<maximum+2<<endl;
	}
	system("pause");
	return 0;
}
