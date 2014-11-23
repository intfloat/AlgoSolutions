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

const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};

int main(){		
	int n, t;
	int off = 50;
	cin>>n>>t;
	queue<pair<int, int> > q;
	int arr[100][100];
	int tmp[100][100];
	memset(arr, 0, sizeof(arr));
	memset(tmp, 0, sizeof(tmp));
	arr[50][50] = n;
	bool change = false;
	if(n >= 4)
		change = true;
	while(change == true){
		change = false;
		memset(tmp, 0, sizeof(tmp));
		for(int i=1; i<99; i++)
		for(int j=1; j<99; j++){
			if(arr[i][j] < 4)
				tmp[i][j] += arr[i][j];
			else{
				change = true;
				tmp[i][j] += arr[i][j]%4;
				for(int k=0; k<4; k++){
					int xx = i+dir_x[k];
					int yy = j+dir_y[k];
					tmp[xx][yy] += arr[i][j]/4;
				}
			}
		}
		for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			arr[i][j] = tmp[i][j];
	}
	
	for(int i=0; i<t; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if(abs(x)>=10 || abs(y)>=10)
			printf("0\n");
		else
			printf("%d\n", arr[x+off][y+off]);
	}
	system("pause");
	return 0;
}
