#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(){	
	int n, m, s, f;
	int step[100005][3];
	cin>>n>>m>>s>>f;
	string res = "";
	int cur = s;
	memset(step, 0, sizeof(step));
	
	for(int i=1; i<=m; i++){
		cin>>step[i][0]>>step[i][1]>>step[i][2];
		if(cur == f){
			cout<<res<<endl;
			return 0;
		}
		for(int j=step[i-1][0]+1; j<step[i][0]; j++){
			if(cur == f){
				cout<<res<<endl;
				return 0;
			}
			if(s<f){
		    	cur++;
		    	res += "R";
			}
			else{
				cur--;
				res += "L";
			}
		}
		
		
		if(cur == f){
			cout<<res<<endl;
			return 0;
		}
		
		if(s<f && cur>=step[i][1]-1 && cur<=step[i][2])
			res += "X";
		else if(s>f && cur>=step[i][1] && cur<=step[i][2]+1)
			res += "X";
		else if(s<f){
			cur++; res+="R";
		}
		else if(s>f){
			cur--; res+="L";
		}
	}
	
	if(s<f){
		for(int i=cur; i<f; i++)
			res += "R";
	}
	else{
		for(int i=cur; i>f; i--)
			res += "L";
	}	
	cout<<res<<endl;
	return 0;
}
