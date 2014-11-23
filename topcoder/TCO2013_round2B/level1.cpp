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

class FruitTrees {
public:
	int maxDist(int, int, int);
	//int res;
	int a[2005], b[2005], c[2005];
	vector<int> v;
	void solve(int s[2005], int cur, int mx){
		//int tmp=cur;		
		for(int i=0; i<=mx; i++){
			if(i>=cur){
				s[i]=s[i-cur];
				continue;
			}
			int t=(i+cur)%mx;
			s[i]=min(s[i], min(i, (mx-i)%cur));
			while(t!=i && s[i]!=0){
				t=(t+cur)%mx;
				s[i]=min(s[i], min(t, (mx-t)%cur));
			}
		}
		return;
	}
	
	int get(int inter){
		if(c[inter]<INT_MAX)
			return c[inter];
		int t=(inter+v[0])%v[1];
		c[inter]=min(c[inter], min(inter, (v[1]-inter)%v[0]));
		while(t!=inter && c[inter]!=0){
			t=(t+v[0])%v[1];
			c[inter]=min(c[inter], min(t, (v[1]-t)%v[0]));
		}
		return c[inter];
	}
};

int FruitTrees::maxDist(int apple, int kiwi, int grape) {	
	v.push_back(apple);
	v.push_back(kiwi);
	v.push_back(grape);
	sort(v.begin(), v.end());
	for(int i=0; i<=v[2]; i++){
		a[i]=INT_MAX;
		b[i]=INT_MAX;
		c[i]=INT_MAX;
	}
	solve(a, v[0], v[2]);
	solve(b, v[1], v[2]);
	//res=0;
	//bool solution=false;
	for(int i=v[0]/2; i>0; i--){
		for(int j=0; j<v[0]; j++){
			if(a[j]<i)
				continue;
			for(int k=0; k<v[1]; k++){
				if(b[k]<i)
					continue;
				int para=(j-k+v[1])%v[1];
				cout<<"j: "<<j<<" k: "<<k<<endl;
				para = para%v[0];
				int tmp=get(para);
				if(tmp>=i){
					return i;
				}
			}			
		}
	}
	return 0;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
