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
const int odd_r[] = {0, 0, 1, 1, -1, -1};
const int odd_c[] = {-1, 1, 0, 1, 0, 1};
const int even_r[] = {0, 0, 1, 1, -1, -1};
const int even_c[] = {1, -1, -1, 0, -1, 0};

class Islands {
public:	
	int beachLength(vector <string>);
};

int Islands::beachLength(vector <string> kingdom) {
	int res = 0;
	int row=kingdom.size();
	int col = kingdom[0].size();
	for(int i=0; i<row; i++)	
	for(int j=0; j<col; j++){
		if(kingdom[i][j] == '#')
			continue;
		if(i%2 == 0){
			for(int k=0; k<6; k++){
				int tmpr = i+even_r[k];
				int tmpc = j+even_c[k];
				if(tmpr<0 || tmpr>=row || tmpc<0 || tmpc>=col)
					continue;
				if(kingdom[tmpr][tmpc] == '#')
					res++;
			}
		}// end if
		else{
			for(int k=0; k<6; k++){
				int tmpr = i+odd_r[k];
				int tmpc = j+odd_c[k];
				if(tmpr<0 || tmpr>=row || tmpc<0 || tmpc>=col)
					continue;
				if(kingdom[tmpr][tmpc] == '#')
					res++;
			}
		}// end else
		
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
