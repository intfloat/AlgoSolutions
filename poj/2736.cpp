#include <iostream>
#include <algorithm>
#include <utility>
#include <stdio.h>

using namespace std;
int main(){
	int n, t;
	pair<int, int> inter[25005];
	scanf("%d%d", &n, &t);
	for(int i=0; i<n; i++)
		scanf("%d%d", &inter[i].first, &inter[i].second);
	sort(inter, inter+n);
	int res = 0;
	bool solution = true;
	if(inter[0].first != 1){
		solution = false;	
	}
	int pre = 1;
	int cur = -1;	
	for(int i=0; i<=n; i++){		
		if(inter[i].first != 1 && inter[i-1].first == 1 && res==0){
			pre = inter[i-1].second;		
			cur = -1;
			res++;
			if(pre >= t)
				break;
			i--;			
			continue;
		}
		if(inter[i].first == 1)
			continue;
		if(inter[i].first<=pre+1 && i!=n){
			if(inter[i].second <= pre)
				continue;
			cur = max(cur, inter[i].second);
		}
		else{
			//cout<<"pre: "<<pre<<endl;
			if(i==n && cur<t){
				solution = false;
				break;
			}
			if(cur <= pre){				
				solution = false;
				break;
			}
			pre = cur;
			cur = -1;
			res++;
			//cout<<inter[i].first<<" "<<inter[i].second<<endl;  
			i--;
			if(pre >= t)
				break;			
		}
	}
		
	if(solution == false)
		cout<<-1<<endl;
	else
		cout<<res<<endl;
	system("pause");
	return 0;
}
