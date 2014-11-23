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
	bool res = false;
	string board[4];
	for(int i=0; i<4; i++)
		cin>>board[i];
	for(int i=0; i<3; i++)
	for(int j=0; j<3; j++){
		int counter = 0;
		for(int m=0; m<2; m++)
		for(int n=0; n<2; n++){
			if(board[i+m][j+n]=='#')
				counter++;
		}
		if(counter>=3 || counter<=1)
			res = true;
	}
	if(res == true)
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	//system("pause");
	return 0;
}
