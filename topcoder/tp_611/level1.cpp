#include <string.h>
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

class LCMSet {
public:
	string equal(vector <int>, vector <int>);
	bool check(long long num, vector<int> v){
		int len = v.size();
		set<long long> s;
		s.clear();
		set<long long>::iterator it, tmp;
		for(int i=0;i<len; i++){
			if((num%v[i])!=0) continue;
			it = s.find(v[i]);
			vector<long long> t;
			t.clear();
			if(it==s.end()){
				s.insert(v[i]);
				for(tmp=s.begin(); tmp!=s.end(); tmp++){
					long long cur = ((*tmp)*(long long)v[i])/__gcd(*tmp, (long long)v[i]);
					if(cur==num) return true;
					if(cur > num) continue;
					if(s.find(cur)==s.end()) t.push_back(cur);
				}
				for(int j=0; j<t.size(); j++){
					if(s.find(t[j])==s.end()) s.insert(t[j]);
				}
			}
		}
		return false;
	}
};

string LCMSet::equal(vector <int> A, vector <int> B) {
	int len1 = A.size();
	int len2 = B.size();
	bool equal = true;
	for(int i=0; i<len1; i++){
		bool exist = false;
		for(int j=0; j<len2; j++){
			if(B[j]==A[i]){
				exist = true;
				break;
			}
		}
		if(exist==false){
			equal = check(A[i], B);
			if(equal==false) return "Not equal";
		}
	}	

	for(int i=0; i<len2; i++){
		bool exist = false;
		for(int j=0; j<len1; j++){
			if(A[j]==B[i]){
				exist = true;
				break;
			}
		}
		if(exist==false){
			equal = check(B[i], A);
			if(equal==false) return "Not equal";
		}
	}
	return "Equal";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!