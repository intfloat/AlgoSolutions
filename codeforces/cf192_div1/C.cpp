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


// 写不下去了。。。T_T 总之就是一些环和链。。。 
int main(){		
	int n, m;
	vector<int> v[100005];
	bool vis[100005], flag[100005];
	memset(vis, false, sizeof(vis));
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		v[x].push_back(y); v[y].push_back(x);
	}
	queue<pair<int, int> > remain, result;
	for(int i=0; i<n; i++){
		if(vis[i]==false){
			vector<int> record;
			record.push_back(i);
			vis[i]=true;
			queue<int> q;
			q.push(i);
			while(q.empty()==false){
				int tmp = q.front();
				q.pop();
				if(vis[tmp]==true)
					continue;
				for(int j=0; j<v[tmp].size(); j++){
					if(vis[v[tmp][j]] == false){
						vis[v[tmp][j]]=true;
						q.push(v[tmp][j]);
						record.push_back(v[tmp][j]);
					}
				}
			}// end while
			for(int j=0; j<record.size(); j++)
				flag[j]=false;
			for(int j=0; j<record.size(); j++){
				if(flag[j]==false){
					flag[j] = true;
					int cur = j, next = (j+2)%(record.size()), begin = j;
					while(next != begin){
						flag[next] = true;
						result.push_back(make_pair(record[cur], record[next]));
						cur = next; next = (next+2)%(record.size());
					}
					if((cur+2)%(record.size()) != next)
						result.push_back(make_pair(record[cur], record[next]));
				}
			}
		}
	}
	system("pause");
	return 0;
}
