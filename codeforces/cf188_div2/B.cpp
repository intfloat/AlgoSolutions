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

string str;
bool okay(string p, int index){
	for(int i=index; i<index+5; i++){
		if(str[i] != p[i-index])
			return false;
	}
	return true;
}

int main(){		
	string m="metal", h="heavy";
	int hcounter = 0;
	cin>>str;
	int len = str.size();
	long long res = 0;
	for(int i=0; i<len-4; i++){
		bool check = okay(m, i);
		if(check == true)
			res += hcounter;
		else{
			check = okay(h, i);
			if(check == true)
				hcounter++;
		}
		if(check == true)
			i += 4;
	}
	cout<<res<<endl;
	//system("pause");
	return 0;
}
