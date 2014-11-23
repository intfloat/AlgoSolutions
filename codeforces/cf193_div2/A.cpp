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
	int n;
	string move;
	cin>>n>>move;
	int len = move.size();
	int number = len/n;
	int res = 0;
	for(int i=1; i<=number; i++){
		int index = i*n;
		if(index >= len)
			break;
		if(move[index-1]==move[index-2]&& 
			move[index-2]==move[index-3])
			res++;
	}
	cout<<res<<endl;
	//system("pause");
	return 0;
}
