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

typedef pair<double, double> point;

int main() {
	int n;
	cin>>n;
	vector<point> v;
	v.clear();
	map<point, int> m;
	for(int i=0; i<n; i++) {
		double a, b;
		cin>>a>>b;
		v.push_back(make_pair(a, b));
		m[v[i]] = i+1;
	}
	sort(v.begin(), v.end());
	
	vector<point> vv;
	vv.clear();
	int len = v.size();
	vv.push_back(v[0]);
	for(int i=1; i<len; i++) {
		if(fabs(v[i].first - v[i-1].first) < 1e-6) {
			vv.pop_back();
			vv.push_back(v[i]);
		}
		else vv.push_back(v[i]);
	}
	len = vv.size();
	stack<int> s;
	while(s.empty() == false) s.pop();
	s.push(0);
	for(int i=1; i<len; i++) {
		while (true) {
			if(s.size() == 1) { s.push(i); break; }
			int p1 = s.top(); s.pop();						
			int p2 = s.top(); s.pop();			
			double x = (vv[p2].second - vv[p1].second)/(vv[p1].first - vv[p2].first);
			double y = vv[p1].second + vv[p1].first * x;
			double tmp = vv[i].first * x + vv[i].second;
			// cout<<"x: "<<x<<" y: "<<y<<" tmp: "<<tmp<<endl;
			if(tmp-y >= -1e-6) { s.push(p2); continue; }
			else { s.push(p2); s.push(p1); s.push(i); break; }
		}
	}
	vector<int> res;
	res.clear();
	while(s.empty() == false) {
		res.push_back(m[vv[s.top()]]);
		s.pop();
	}
	sort(res.begin(), res.end());
	vector<int>::iterator it;
	for (it=res.begin(); it!=res.end(); it++) {
		cout<<*it<<" ";
		// cout<<v[*it].first<<" "<<v[*it].second<<endl;
	}
	return 0;
}
