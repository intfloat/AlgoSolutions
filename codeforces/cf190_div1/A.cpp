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
	long long a, b, x, y, curx, cury;	
	string s;
	cin>>a>>b;
	cin>>s;
	int len = s.size();
	
	curx = 0; cury = 0;
	for(int i=0; i<len; i++){
		if(s[i]=='U')
			cury++;
		else if(s[i]=='D')
			cury--;
		else if(s[i]=='L')
			curx--;
		else if(s[i]=='R')
			curx++;
	}
	x = curx; y = cury;
	
	bool solution = false;
	curx = 0; cury = 0;
	for(int i=-1; i<len; i++){
		
		if(i>=0){
			if(s[i]=='U')
				cury++;
			else if(s[i]=='D')
				cury--;
			else if(s[i]=='L')
				curx--;
			else if(s[i]=='R')
				curx++;
		}
					
		long long tx = a - curx;
		long long ty = b - cury;	
		if(tx*x<0 || ty*y<0)
			continue;
		tx = abs(tx); ty = abs(ty);
		long long xx = abs(x), yy = abs(y);
		if(xx == 0){
			if(tx != 0)
				continue;		
		}
		if(yy == 0){
			if(ty != 0)
				continue;
		}
		if(((xx!=0)&&(tx%xx!=0)) || ((yy!=0)&&(ty%yy!=0)))
			continue;
		if(xx==0 || yy==0 || tx/xx == ty/yy){
			solution = true;
			break;
		}		
		
	}
	
	if(solution == true)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	//system("pause");
	return 0;
}
