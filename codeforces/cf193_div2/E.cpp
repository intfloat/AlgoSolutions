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
	cout<<20000<<" "<<5678<<endl;
	srand(time(0));
	for(int i=0; i<20000; i++){
		cout<<rand()%(1000000)+100000000<<" ";
	}
	cout<<endl;
	//system("pause");
	return 0;
}
