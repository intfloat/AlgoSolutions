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
	freopen("sample.txt", "w", stdout);
	srand(0);
	cout<<999<<endl;
	for(int i=1; i<=999; i++){
		int r = (rand()%i)+1;
		if(i<999)
			cout<<r<<" ";
		else cout<<r<<endl;
	}
	return 0;
}
