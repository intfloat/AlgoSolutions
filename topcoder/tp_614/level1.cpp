// level1.cpp
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

class MinimumSquare {
public:
	long long minArea(vector <int>, vector <int>, int);
};

// I am just too stupid...
long long MinimumSquare::minArea(vector <int> x, vector <int> y, int K) {
	int len = x.size();
	vector<pair<long long, long long> > v, w, t;
	v.clear(); w.clear();
	long long res = 6e18;
	for (int i=0; i<len; i++){
		v.push_back(make_pair(x[i], y[i]));
		w.push_back(make_pair(y[i], x[i]));
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	for(int i=0; i<len; i++){
		int left = i;
		int right = i+K-1;
		if (right >= len) break;
		long long xx = v[right].first-v[left].first+2;		
		t.clear();
		for(int j=0; j<len; j++){
			if(v[j].first>=v[left].first && v[j].first<=v[right].first)
				t.push_back(make_pair(v[j].second, v[j].first));
		}
		sort(t.begin(), t.end());
		int tlen = t.size();
		cout<<"tlen: "<<tlen<<endl;
		for(int j=0; j<tlen; j++){
			int r = j+K-1;
			if(r>=tlen) break;
			long long yy = t[r].first-t[j].first+2;
			if(yy <= xx){
				res = min(res, xx*xx);				
			}
			else {
				res = min(res, yy*yy);
			}
		}				

		xx = w[right].first-w[left].first+2;
		t.clear();
		for(int j=0; j<len; j++){
			if(w[j].first>=w[left].first && w[j].first<=w[right].first)
				t.push_back(make_pair(w[j].second, w[j].first));
		}
		sort(t.begin(), t.end());
		tlen = t.size();
		cout<<"tlen: "<<tlen<<endl;
		for(int j=0; j<tlen; j++){
			int r = j+K-1;
			if(r>=tlen) break;
			long long yy = t[r].first-t[j].first+2;
			if(yy <= xx){
				res = min(res, xx*xx);				
			}
			else {
				res = min(res, yy*yy);
			}
		}		
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!