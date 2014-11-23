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

class PenguinTiles {
public:
	int minMoves(vector <string>);
};

int PenguinTiles::minMoves(vector <string> tiles) {
	int row=tiles.size();
	int col=tiles[0].size();
	for(int i=0;i<row;i++)
	for(int j=0;j<col;j++){
		if(tiles[i][j]=='.'){
			if(i==(row-1) && j==(col-1))
				return 0;
			else if(i==(row-1) || j==(col-1))
				return 1;
			else return 2;
		}
	}
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
