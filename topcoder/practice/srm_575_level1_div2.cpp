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

class TheSwapsDivTwo {
public:
	int find(vector <int>);
};

int TheSwapsDivTwo::find(vector <int> sequence) {
	int len = sequence.size();
	int counter = 0;
	bool dup = false;
	for(int i=0; i<len; i++)
	for(int j=i+1; j<len; j++){
		if(sequence[i]!=sequence[j])
			counter++;
		else
			dup = true;
	}
	if(dup == false)
		return counter;
	else
		return counter+1;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
