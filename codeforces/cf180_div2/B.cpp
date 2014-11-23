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
	int t, sx, sy, ex, ey;
	cin>>t>>sx>>sy>>ex>>ey;
	string str;
	cin>>str;
	int curx=ex-sx, cury=ey-sy;
//	int tmpx=0, tmpy=0;
	int res=-1;
	for(int i=0; i<t; i++){		
		if(str[i]=='S' && cury<0)
			cury++;
		else if(str[i]=='N' && cury>0)
			cury--;
		else if(str[i]=='W' && curx<0)
			curx++;
		else if(str[i]=='E' && curx>0)
			curx--;		
		//cout<<curx<<" "<<cury<<endl;
		if(curx==0 && cury==0){
			res = i+1;
			break;
		}
	}
	cout<<res<<endl;
	//system("pause");
	return 0;
}
