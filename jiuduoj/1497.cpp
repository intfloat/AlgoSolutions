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

int main(){
	int row, col;
	vector<bool> arr[105];
	int c[105][105];
	while(cin>>row>>col){
		int upp = 0;
		for(int i=0; i<row; i++) {
			arr[i].clear();
			for(int j=0; j<col; j++) {
				bool tmp;
				cin>>tmp;
				upp += (tmp==true);
				arr[i].push_back(tmp);
			}
		}
		for(int i=0; i<col; i++)
			c[0][i] = (arr[0][i]==1);
		for(int i=1; i<row; i++) {
			for (int j=0; j<col; j++) {
				if (arr[i][j]==0) c[i][j] = 0;
				else c[i][j] = c[i-1][j]+1;
			}
		}
		int res = 0;
		for(int i=row-1; i>=0; i--) {
			if (res == upp) break;
			for(int j=col-1; j>=0; j--) {
				if (res == upp) break;
				int pos = j;
				int cur = c[i][pos];
				while(pos>=0 && cur>0) {
					cur = min(cur, c[i][pos]);
					res = max(res, cur*(j-pos+1));
					if (res == upp) break;
					--pos;
				}				
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
