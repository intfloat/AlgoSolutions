// level2.cpp
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

const long long MOD = 1000000007;
class RandomGCD {
public:
	int countTuples(int, int, int, int);
	long long fast_pow(long long num, long long p){
		if(num==1) return 1;
		if(p==0) return 1;
		if(p==1) return num%MOD;
		long long tmp = fast_pow(num, p/2)%MOD;
		tmp = (tmp*tmp)%MOD;
		if(p%2==1) tmp = (tmp*num)%MOD;
		return tmp%MOD;
	}
};

// got challenged...
int RandomGCD::countTuples(int N, int K, int low, int high) {
	vector<long long> v;
	v.clear();
	for(int i=low; i<=high; i++){
		if(i%K==0) v.push_back(i/K);
	}
	int len = v.size();
	if(len==0) return 0;
	if(len==1 && v[0]==1) return 1;
	if(len==1 && v[0]>1) return 0;	
	set<long long> s;
	s.clear();
	for(int i=0; i<len; i++){
		// overflow here...
		for(int j=1; j*j<=v[i]; j++){
			if(v[i]%j==0){
				s.insert(j);
				s.insert(v[i]/j);
			}
		}
	}	
	long long res = fast_pow(len, N)%MOD;
	set<long long>::iterator it;
	for(it=s.begin(); it!=s.end(); it++){
		long long num = 0;
		long long t = *it;
		if(t==1) continue;	
		long long pre = countTuples(N, t, v[0], v[len-1]);
		res = (res+MOD-pre)%MOD;
	}
	return res%MOD;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!