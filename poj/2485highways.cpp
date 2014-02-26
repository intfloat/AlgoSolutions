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

int road[505][505], n;
bool check[505][505];

// check if dis is okay for current road
bool okay(int dis){
	bool connect[505];
	memset(connect, false, sizeof(connect));
	queue<int> q;
	q.push(0); connect[0]=true;
	int counter = 1;
	while(q.empty() == false){
		int tmp = q.front();
		q.pop();
		for(int i=0; i<n; i++){
			if(check[tmp][i]==true && connect[i]==false){
				connect[i]=true;
				q.push(i);
				counter++;
			}			
		}// end for loop
	}// end while
	return (counter==n);
}

int main(){		
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", road[i]+j);
		int left = 0, right = 65536;
		
		while(left < right){
			int middle = (left+right)>>1;
			// construct a graph
			for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				check[i][j] = (road[i][j]<=middle);
			if(okay(middle)==true)
				right = middle;
			else
				left = middle+1;
		}
		printf("%d\n", left);		
	}
	system("pause");
	return 0;
}
