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

struct Point{
	int x, y;
};

double ccw(Point a, Point b, Point c){
	double res = (double)(a.x-c.x)*(b.y-c.y)-(double)(b.x-c.x)*(a.y-c.y);
	return res/2.0;
}

int main(){	
	int n;
	Point p[305];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>p[i].x>>p[i].y;
	double res = 0;
	for(int i=0; i<n; i++)
	for(int j=i+1; j<n; j++){
		double pos=0, neg=0;
		for(int k=0; k<n; k++){
			double tmp = ccw(p[i], p[j], p[k]);
			if(tmp < 0)
				neg = max(neg, -tmp);
			else
				pos = max(pos, tmp);
		}
		if(neg>1e-9 && pos>1e-9)
			res = max(res, neg+pos);
	}
	
	cout<<fixed<<setprecision(6)<<res<<endl;
	//system("pause");
	return 0;
}
