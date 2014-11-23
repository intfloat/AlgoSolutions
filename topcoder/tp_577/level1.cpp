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

class EllysRoomAssignmentsDiv1 {
public:
	double getAverage(vector <string>);
	string str;
	vector<int> rate;
	int number;
	int len, room;
	int find(int elly){
		for(int i=0; i<len; i++){
			if(rate[i]==elly)
				return i/room;
		}
		return 0;
	}
	
	void split(){
		for(int i=0; i<len; i++){
			int tmp = 1000;
			int value = 0;
			if(str[i]!=' '){
				for(int j=i; j<i+4; j++){
					value += tmp*(str[j]-'0');
					tmp = tmp/10;
				}
				i += 4;
				rate.push_back(value);
			}
		}
		return;
	}
	
};

double EllysRoomAssignmentsDiv1::getAverage(vector <string> ratings) {
	len = ratings.size();
	str = "";
	for(int i=0; i<len; i++)
		str+=ratings[i];
	len = str.size();
	split();
	int elly = rate[0];
	len = rate.size();
//	cout<<"len: "<<len<<endl;
//	for(int i=0; i<len; i++)
//		cout<<rate[i]<<" ";
//	cout<<endl;
	sort(rate.begin(), rate.end(), greater<int>());	
	room = (len+19)/20;
	int remain = len%room;
	double sum1 = 0;
	double sum2 = 0;
	double res = 0;
	int n=(len)/room;
	int group = len/room;
	double p1 = remain*1.0/(double)room;
	double p2 = 1.0-p1;
//	cout<<"n: "<<n<<endl;
	//cout<<"p1: "<<p1<<endl;
//	cout<<"p2: "<<p2<<endl;
	//cout<<"room: "<<room<<endl;
//	cout<<"remain: "<<remain<<endl;
	int pos = find(elly);
	
	for(int i=0; i<group; i++){
		if(i==pos)
			continue;
		for(int j=i*room; j<(i+1)*room; j++)
			sum1+=rate[j];
	}
	sum1 = sum1*(1.0/(double)room)+elly;
	if(pos == (len-1)/room){
		int tmp = (len+room-1)/room;
		res = (1.0/(double)tmp)*sum1;
		return res;
	}
	for(int i=len-1; i>=len-remain; i--){
		if(pos == (len-1)/room)
			break;
		sum2 += rate[i];
	}
	if(remain!=0)
		sum2 = sum2*(1.0)/remain;
	//cout<<"sum1: "<<sum1<<endl;
	//cout<<"sum2: "<<sum2<<endl;
	res = p1*((1.0/(double)(n+1))*(sum1+sum2))+p2*((1.0/(double)n)*sum1);
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

