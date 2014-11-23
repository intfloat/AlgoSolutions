 #include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

using namespace std;

class ArcadeManao {
public:
	int shortestLadder(vector <string>, int, int);
};

int ArcadeManao::shortestLadder(vector <string> level, int coinRow, int coinColumn) {
	int row = level.size();
	int col = level[0].size();
	bool used[55][55];
	int res=0;
	if(coinRow == row)
		return 0;
	for(int i=1; i<row; i++){
		memset(used, false, sizeof(used));
		queue<pair<int, int> > q;
		for(int j=0; j<col; j++){
			q.push(make_pair(row-1, j));
			used[row-1][j] = true;
		}
		bool solution = false;
		pair<int, int> tmp;
		while(q.empty()==false){		
			tmp = q.front();
			q.pop();
			if(tmp.first==coinRow-1 && tmp.second==coinColumn-1){
				solution = true;
				break;
			}
			for(int j=0; j<row; j++){
				if(j > i)
					break;
				int pos1 = tmp.first+j;
				int pos2 = tmp.first-j;
				if(pos1<row && used[pos1][tmp.second]==false && level[pos1][tmp.second]=='X'){
					used[pos1][tmp.second] = true;
					q.push(make_pair(pos1, tmp.second));
				}
				if(pos2>=0 && used[pos2][tmp.second]==false && level[pos2][tmp.second]=='X'){
					used[pos2][tmp.second] = true;
					q.push(make_pair(pos2, tmp.second));
				}				
			}
			//居然理解错了混蛋。。。。 
			for(int k=-1; k<=1; k++){
				int pos = k+tmp.second;
				if(pos>=0 && pos<col && used[tmp.first][pos]==false && level[tmp.first][pos]=='X'){
					used[tmp.first][pos] = true;
					q.push(make_pair(tmp.first, pos));
				}
			}
			
		}
		if(solution == true){
			res = i;
			break;
		}
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
