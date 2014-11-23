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

const int dir_x[] = {0, 0, -1, 1};
const int dir_y[] = {1, -1, 0, 0};

int main(){		
	int row, col;
	string board[505];
	int flag[505][505];
	int step = 0;
	vector<pair<int, int> > v;
	vector<int> typ;
	cin>>row>>col;
	for(int i=0; i<row; i++)
		cin>>board[i];
	memset(flag, 0, sizeof(flag));
	queue<pair<int, int> > q;
	vector<pair<char, pair<int, int> > > res;
	
	for(int i=0; i<row; i++)
	for(int j=0; j<col; j++){
		if(board[i][j]=='#' || flag[i][j]!=0)
			continue;
		flag[i][j] = 1;
		while(q.empty() == false)
			q.pop();
		v.clear(); typ.clear();
		q.push(make_pair(i, j));
		v.push_back(make_pair(i, j));
		typ.push_back(1);
		int number = 1;
		while(q.empty()==false){
			number++;
			pair<int, int> cur = q.front();
			q.pop();
			int x=cur.first, y=cur.second;
			for(int k=0; k<4; k++){
				int tmpx = x+dir_x[k];
				int tmpy = y+dir_y[k];
				if(tmpx<0 || tmpx>=row || tmpy<0 || tmpy>=col)
					continue;
				if(flag[tmpx][tmpy]!=0 || board[tmpx][tmpy]=='#')
					continue;
				flag[tmpx][tmpy] = number;
				q.push(make_pair(tmpx, tmpy));
				v.push_back(make_pair(tmpx, tmpy));
				typ.push_back(number);
			}
			//number++;
		}
		int len = v.size();
		for(int k=0; k<len; k++){
			res.push_back(make_pair('B', make_pair(v[k].first, v[k].second)));
			step++;
		}
		for(int k=len-1; k>0; k--){
			res.push_back(make_pair('D', make_pair(v[k].first, v[k].second)));
			res.push_back(make_pair('R', make_pair(v[k].first, v[k].second)));
			step += 2;
		}
	}
	
	cout<<step<<endl;
	for(int i=0; i<step; i++){
		cout<<res[i].first<<" "<<res[i].second.first+1<<" "<<res[i].second.second+1<<endl;
	}
	//system("pause");
	return 0;
}
