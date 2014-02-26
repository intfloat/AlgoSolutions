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

const int INF = 9999999;

int main(){		
	int n, g[105][105];
	char tmp[50];
	memset(g, 0, sizeof(g));
	cin>>n;
	for(int i=1; i<n; i++)
	for(int j=0; j<i; j++){
		cin>>tmp;
		if(tmp[0]=='x')
			g[i][j]=INF;
		else
			g[i][j]=atoi(tmp);
		g[j][i] = g[i][j];
	}
	
	for(int k=0; k<n; k++)
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
	int res = 0;
	for(int i=0; i<n; i++)
		res = max(res, g[0][i]);
	cout<<res<<endl;
	system("pause");
	return 0;
}
