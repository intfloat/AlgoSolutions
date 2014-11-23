#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <string.h>
#include <ctime>

using namespace std;

class TheMatrix {
public:
	int MaxArea(vector <string>);
};

// O(N^3) solution is possible
int TheMatrix::MaxArea(vector <string> board) {
	int row = board.size();
	int col = board[0].size();
	int rdp[105][105], cdp[105][105];
	memset(rdp, 0, sizeof(rdp));
	memset(cdp, 0, sizeof(cdp));
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			// set length of row span
			if(j==0)
				rdp[i][j] = 1;			
			else if(board[i][j]!=board[i][j-1])
				rdp[i][j] = rdp[i][j-1]+1;			
			else rdp[i][j] = 1;		
			// set length of column span
			if(i==0) cdp[i][j] = 1;
			else if(board[i][j]!=board[i-1][j])
				cdp[i][j] = cdp[i-1][j]+1;
			else cdp[i][j] = 1;
		}
	}// end external for loop

	int res = 1;
	// O(N^3) at worst case
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			int height = cdp[i][j];
			for(int k=j; k>=0; k--){
				if((j-k+1)>rdp[i][j]) break;
				height = min(height, cdp[i][k]);
				res = max(res, height*(j-k+1));
			}
		}
	}// end external for loop
	return res;
}

// <%:testing-code%>
//Powered by [KawigiEdit] 2.0!
