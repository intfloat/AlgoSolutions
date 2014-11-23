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
	freopen("out.txt", "w", stdout);
	srand(unsigned(time(0)));
	for(int i=0; i<49; i++){
		for(int j=0; j<50; j++){
			int tmp = rand()%4;
			if(tmp==0)
				cout<<"X";
			else cout<<".";
		}
		cout<<endl;
	}
	for(int i=0; i<50; i++)
		cout<<"X";
	cout<<endl;
	//system("pause");
	return 0;
}
