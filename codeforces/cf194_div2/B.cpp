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

pair<int, int> points[8], ps[8];
bool contains(int x, int y){
	pair<int, int> tmp = make_pair(x, y);
	for(int i=0; i<8; i++){
		if(points[i]==tmp)
			return true;
	}
	return false;
}

int main(){			
	int x, y;
	vector<int> xx, yy;
	for(int i=0; i<8; i++){
		cin>>x>>y;
		points[i] = make_pair(x, y);
		ps[i] = make_pair(y, x);
	}
	sort(points, points+8);
	sort(ps, ps+8);
	for(int i=0; i<8; i++){
		if(i==0 || points[i].first!=points[i-1].first)
			xx.push_back(points[i].first);
		if(i==0 || ps[i].first!=ps[i-1].first)
			yy.push_back(ps[i].first);
	}
	bool solution = true;
	if(xx.size()!=3 || yy.size()!=3)
		solution = false;
	if(solution == true){
		//cout<<"here"<<endl;
		for(int i=0; i<3; i++)
		for(int j=0; j<3; j++){
			if(i==1 && j==1 && contains(xx[i], yy[j])==true)
				solution=false;
			else if(!(i==1 && j==1) && contains(xx[i], yy[j])==false)
				solution = false;
		}
	}
	
	if(solution == true)
		cout<<"respectable"<<endl;
	else
		cout<<"ugly"<<endl;
	//system("pause");
	return 0;
}
