#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int main(){
	int n;
	bool check[201][201];
	memset(check, false, sizeof(check));
	
	cin>>n;
	for(int i=0; i<n; i++){
		int tmp;
		while(cin>>tmp && tmp)
			check[i][tmp-1] = true;
	}	
	//shortest path
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	for(int k=0; k<n; k++)
		check[j][k] = check[j][k] || (check[j][i] && check[i][k]);
	
	bool flag[205];
	int res = 0;
	int counter = n;
	memset(flag, true, sizeof(flag));
	while(counter > 0){
		queue<int> q;
		for(int i=0; i<n; i++){
			if(flag[i] == true){
				q.push(i);
				counter--;
				flag[i] = false;
				break;
			}
		}//end for loop
		while(q.empty() == false){
			int tmp = q.front();
			q.pop();
			for(int i=0; i<n; i++){
				if(flag[i]==true 
					&& check[i][tmp]==true 
					&& check[tmp][i]==true){
					flag[i] = false;
					counter--;
					q.push(i);	
				}
			}
		}//end while loop
		
		res++;
	}
	cout<<res<<endl;
	system("pause");
	return 0;
}
