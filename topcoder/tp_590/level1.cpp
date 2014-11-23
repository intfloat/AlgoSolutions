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

class FoxAndChess {
public:
	string ableToMove(string, string);
};

string FoxAndChess::ableToMove(string begin, string target) {
	string str1="", str2="";
	vector<int> v1, v2;
	v1.clear(); v2.clear();
	int len = begin.size();
	for(int i=0; i<len; i++){
		if(begin[i]!='.'){
			str1 += begin[i];
			v1.push_back(i);
		}
		if(target[i]!='.'){
			str2 += target[i];
			v2.push_back(i);
		}
	}
	if(str1 != str2)
		return "Impossible";
	len = v1.size();
	for(int i=0; i<len; i++){
		if(begin[v1[i]]=='L' && v2[i]>v1[i])
			return "Impossible";
		if(begin[v1[i]]=='R' && v2[i]<v1[i])
			return "Impossible";
	}
	return "Possible";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
