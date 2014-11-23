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

class TeamContestEasy {
public:
	int worstRank(vector <int>);
};

int TeamContestEasy::worstRank(vector <int> strength) {
	int len = strength.size();
	int team = (len/3)-1;
	int us = strength[0]+strength[1]+strength[2]
			-min(strength[0], min(strength[1],strength[2]));
	vector<int> v;
	for(int i=3; i<len; i++)
		v.push_back(strength[i]);
	len = v.size();
	sort(v.begin(), v.end());
	pair<int, int> record = make_pair(0,0);
	int mini = 10000000;
	int res = 1;
	for(int i=0; i<team; i++){
		sort(v.begin(), v.end());
		mini = 10000000;
		for(int j=len-1; j>0; j++){
			if(v[0]+v[j] > us){
				record = make_pair(0, j);
				mini = v[0]+v[j];
				break;
			}
		}
		if(mini < 10000000){
			res++;
			v[record.first] = 0;
			v[record.second] = 0;
		}
		else
			break;
	}
	return res;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	TeamContestEasy team;	
	srand(unsigned(time(0)));
	int len = 48;
	int t = 10;
//	while(t--){
		vector<int> s;
//		while(s.size()>0)
//			s.clear();
		for(int i=0; i<len; i++){
			s.push_back((rand())%(100000));
//			cout<<i<<": "<<s[i]<<endl;
		}
		for(int i=0; i<48; i++)
			cout<<s[i]<<endl;
		//cout<<endl;
		cout<<"result: "<<team.worstRank(s)<<endl;
		cout<<flush;
//	}
	return 0;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
