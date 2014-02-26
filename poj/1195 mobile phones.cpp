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

int matrix[1030][1030];
int lowbit[1100];
int length;
//int sum[1030][1030];

// ¶þÎ¬Ê÷×´Êý×é 
// Add certain value to one element
void add(int col, int row, int value){
	while(col <= length){
		int tmp = row;
		while(tmp <= length){
			matrix[tmp][col] += value;
			tmp += lowbit[tmp];
		}
		col += lowbit[col];
	}
	return;
}

// Query sum in a certain range
int query(int col, int row){
	int res = 0;
	while(col > 0){
		int tmp = row;
		while(tmp > 0){
			res += matrix[tmp][col];
			tmp -= lowbit[tmp];
		}
		col -= lowbit[col];
	}
	return res;
}

int main(){	
	int command;
	int x, y, a;
	int left, top, bott, right;
	for(int i=0; i<1100; i++)
		lowbit[i] = i&(-i);
	while(cin>>command){
		if(command == 0){
			scanf("%d", &length);
			//cin>>length;
			memset(matrix, 0, sizeof(matrix));			
		}
		else if(command == 1){
			scanf("%d%d%d", &x, &y, &a);
			//cin>>x>>y>>a;
			add(x+1, y+1, a);
		}
		else if(command == 2){
			scanf("%d%d%d%d", &left, &bott, &right, &top);
			//cin>>left>>bott>>right>>top;
			left++; bott++; right++; top++;
			int res = query(right, top)-query(left-1, top)-query(right, bott-1)+query(left-1, bott-1);
			printf("%d\n", res);
			//cout<<res<<endl;
		}
		else
			return 0;
	}
	//system("pause");
	return 0;
}
