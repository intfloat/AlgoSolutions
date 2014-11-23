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
	pair<int, int> record = make_pair(0,0);
	int mini = 10000000;
	int res = 1;
	for(int i=0; i<team; i++){
		mini = 10000000;
		for(int j=0; j<len; j++)
		for(int k=(j+1); k<len; k++){
			if(v[j]+v[k] > us && (v[j]+v[k] < mini)){
				record = make_pair(j, k);
				mini = v[j]+v[k];
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
	freopen("out.txt","w", stdout);
	TeamContestEasy team;
	vector<int> s;
	//srand(unsigned(time(0)));
	int len = 48;
	int tmp;
	int t = 10;
	//while(t--){
		for(int i=0; i<len; i++){
			cin>>tmp;
			s.push_back(tmp);
			//cout<<s[i]<<endl;
		}
		//cout<<endl;
		cout<<"result: "<<team.worstRank(s)<<endl;
	//}
	return 0;
}

///<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
