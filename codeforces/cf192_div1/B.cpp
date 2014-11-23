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

const int INF = 99999999;
const int dir_x[] = {-1, 1, 0, 0};
const int dir_y[] = {0, 0, 1, -1};
const int SIZE = 1005;

int main(){		
	int row, col;
	int dis[SIZE][SIZE];
	string arr[SIZE];
	cin>>row>>col;
	for(int i=0; i<row; i++)
		cin>>arr[i];
	queue<pair<int, int> > q;	
	pair<int, int> pos;
	for(int i=0; i<row; i++)
	for(int j=0; j<col; j++){
		dis[i][j] = INF;
		if(arr[i][j]=='E'){
			dis[i][j] = 0;
			q.push(make_pair(i, j));
		}
		else if(arr[i][j]=='S')
			pos = make_pair(i, j);
	}
	
	while(q.empty() == false){
		pair<int, int> tmp = q.front();
		q.pop();
		int x = tmp.first; int y = tmp.second;
		for(int i=0; i<4; i++){
			int xx = x+dir_x[i];
			int yy = y+dir_y[i];
			if(xx<0 || xx>=row || yy<0 || yy>=col)
				continue;
			if(arr[xx][yy]=='T')
				continue;
			if(dis[x][y]+1 < dis[xx][yy]){
				dis[xx][yy] = dis[x][y]+1;
				q.push(make_pair(xx, yy));
			}
		}
	}

	long long res = 0;
	int sx = pos.first;  int sy = pos.second;
	int cur = dis[sx][sy];
	for(int i=0; i<row; i++)
	for(int j=0; j<col; j++){
		if(dis[i][j]<=cur && arr[i][j]>'0' && arr[i][j]<='9')
			res += arr[i][j]-'0';
	}
	cout<<res<<endl;
	//system("pause");
	return 0;
}
