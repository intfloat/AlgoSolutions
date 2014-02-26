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

// six operations
const string op[] = {"FILL(1)", "FILL(2)", "DROP(1)", 
					"DROP(2)", "POUR(1,2)", "POUR(2,1)"};
struct Node{
	int row, col;
	int ty;
};

int main(){	
	int a, b, c;
	Node path[105][105];
	bool visited[105][105];
	memset(visited, false, sizeof(visited));
	cin>>a>>b>>c;	
	
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	bool hasSolution = false;
	int resr, resc;
	
	while(q.empty() == false){
		pair<int, int> top = q.front();
		if(top.first==c || top.second==c){
			hasSolution = true;
			resr = top.first; resc = top.second;
			break;
		}
		q.pop();
		for(int i=0; i<6; i++){
			int tmpr=top.first, tmpc=top.second;
			if(i==0)
				tmpr = a;
			else if(i==1)
				tmpc = b;
			else if(i==2)
				tmpr = 0;
			else if(i==3)
				tmpc = 0;
			else if(i==4){
				int cc = min(b, tmpr+tmpc);
				if(tmpr+tmpc <= b) 
					tmpr = 0;
				else
					tmpr -= b-tmpc;
				tmpc = cc;
			}
			else if(i==5){
				int rr = min(a, tmpr+tmpc);
				if(tmpr+tmpc <= a)
					tmpc = 0;
				else
					tmpc -= a-tmpr;
				tmpr = rr;
			}
			
			if(visited[tmpr][tmpc] == true)
				continue;
			visited[tmpr][tmpc] = true;
			path[tmpr][tmpc].row = top.first;
			path[tmpr][tmpc].col = top.second;
			path[tmpr][tmpc].ty = i;
			q.push(make_pair(tmpr, tmpc));
		}
	}
	
	
	if(hasSolution == false)
		cout<<"impossible"<<endl;
	else{
		stack<string> s;
		while(!(resr==0 && resc==0)){
			s.push(op[path[resr][resc].ty]);
			int tr = path[resr][resc].row;
			int tc = path[resr][resc].col;
			resr = tr; resc = tc;
		}
		cout<<s.size()<<endl;
		while(s.empty()==false){
			cout<<s.top()<<endl;
			s.pop();
		}
	}
	system("pause");
	return 0;
}
