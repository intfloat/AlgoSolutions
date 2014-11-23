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

class Excavations {
public:
	long long count(vector <int>, vector <int>, vector <int>, int);
};

// 水平有限，搞不出来啊。。。 
long long Excavations::count(vector <int> kind, vector <int> depth, vector <int> found, int K) {
	vector<int> dep = depth, d;
	sort(dep.begin(), dep.end());
	d.push_back(dep[0]);
	for(int i=1; i<dep.size(); i++){
		if(dep[i]!=dep[i-1])
			d.push_back(dep[i]);
	}
	
	long long c[55][55];
	memset(c, 0, sizeof(c));
	for(int i=0; i<55; i++){
		c[i][i] = 1;
		c[i][0] = 1;
	}
	for(int i=1; i<55; i++)
	for(int j=1; j<=i; j++)
		c[i][j] = c[i-1][j]+c[i-1][j-1];
		
	long long res = 0;
	for(int i=0; i<d.size(); i++){
		int kk = 0;
		if(i==0)
			kk = K;
		else
			kk = K-1;		
		
	}
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
