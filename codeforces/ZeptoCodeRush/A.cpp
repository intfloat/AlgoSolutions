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

typedef pair<int, int> point;

int get(vector<point> v1, vector<point> v2, int x) {
	int res = 0;	
	int hei = x;
	int cur = 0;
	while(true) {
		int index = -1;
		int mx = -1;
		if (cur == 0) {
			for (int i=0; i<v1.size(); i++) {
				if (v1[i].first<=hei && v1[i].second>mx) {
					index = i;
					mx = v1[i].second;
				}
			}
			if (index < 0) break;
			else {
				hei += v1[index].second;
				++res;
				cur = 1;
				v1.erase(v1.begin() + index);
			}
		}
		else{
			for (int i=0; i<v2.size(); i++) {
				if (v2[i].first<=hei && v2[i].second>mx) {
					index = i;
					mx = v2[i].second;
				}
			}
			if (index < 0) break;
			else {
				hei += v2[index].second;
				++res;
				cur = 0;
				v2.erase(v2.begin() + index);
			}
		}
	}
	return res;
}

int main(){
	int n, x;
	int t, h, m;
	cin>>n>>x;
	vector<point> t1, t2;
	t1.clear(); t2.clear();
	for(int i=0; i<n; i++) {
		cin>>t>>h>>m;
		if (t == 0) t1.push_back(make_pair(h, m));
		else t2.push_back(make_pair(h, m));
	}
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	int res1 = get(t1, t2, x);
	int res2 = get(t2, t1, x);
	cout<<max(res1, res2)<<endl;
	return 0;
}
