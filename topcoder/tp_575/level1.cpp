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

class TheNumberGameDivOne {
public:
	string find(long long);
};

// 打表看规律啊混蛋！！ 
string TheNumberGameDivOne::find(long long n) {
	int counter = 0;
	long long t = n;
	while(t%2 == 0){
		counter++;
		t = t/2;
	}	
	//漏了一句，T_T 
	if(n == 1)
		return "Brus";
	if(t == 1){
		if(counter%2 == 1)
			return "Brus";
		else
			return "John";
	}
	if(counter > 0)
		return "John";
	return "Brus";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
