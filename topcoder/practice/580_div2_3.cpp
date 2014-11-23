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
#include <ctime>

using namespace std;
const int INF=9999999;
class WallGameDiv2 {
public:
	int play(vector <string>);
	vector<string> costs;
	int w, h;
	int dp[50][50][3];
	
	int worstPath(int y, int x, int d){
    	
	    int res = dp[y][x][d];
    	if (res == -1) {
        	int c = costs[y][x]-'0';
	        if ( costs[y][x] == 'x') {
    	        // Invalid
        	    res = -INF;
	        } else if (y == h-1) {
    	        // Base case, the bottom is the end of the road:
        	    res = c;
	        } else {
    	        // Move down:
        	    res = c + worstPath(y+1, x, 0);

            	// Move left (as long as the previous move was not right)
	            if ( (d != 2) && (x > 0) ) {
    	            res = std::max(res, c + worstPath(y, x-1, 1) );
        	    }
	            // Move right (as long as the previous move was not left)
    	        if ( (d != 1) && (x < w-1) ) {
        	        res = std::max(res, c + worstPath(y, x+1, 2) );
            	}
	        }
    	    // memoize the result:
        	dp[y][x][d] = res;
	    }
    	return res;
	}
};

int WallGameDiv2::play(vector <string> costs) {
    //Save some variables for use by the worstPath function:
	
    this->costs = costs;
    w = costs[0].size();
    h = costs.size();
    // initialize the whole dp[][][] array with -1:
    memset(dp, -1, sizeof(dp));
    // Solution: x=0, y=0, d=0
    return worstPath(0,0, 0);	
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
