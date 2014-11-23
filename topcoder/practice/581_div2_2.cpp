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

class SurveillanceSystem {
public:
	string getContainerInfo(string, vector <int>, int);
};

string SurveillanceSystem::getContainerInfo(string containers, vector <int> reports, int L) {
	int len = containers.size();
	int nn[55], mm[55], lap[55], counter[55];
	memset(nn, 0, sizeof(nn));
	memset(mm, 0, sizeof(mm));
	memset(counter, 0, sizeof(counter));

	for(int i=0; i<=len-L; i++){
		int tmp = 0;
		for(int j=i; j<i+L; j++){
			if(containers[j]=='X')
				tmp++;
		}
		counter[i] = tmp;
		nn[tmp]++;
	}
	for(int i=0; i<reports.size(); i++)
		mm[reports[i]]++;
	string res = containers;
	for(int i=0; i<res.size(); i++)
		res[i] = '-';
	
	for(int i=0; i<55; i++){
		if(mm[i] > 0){
			int bound = nn[i]-mm[i];
			cout<<"bound: "<<bound<<endl;
			memset(lap, 0, sizeof(lap));
			for(int j=0; j<=len-L; j++){
				if(counter[j]==i){
					for(int k=j; k<j+L; k++)
						lap[k]++;
				}
			}
			for(int j=0; j<55; j++){
				if(lap[j] > bound)
					res[j] = '+';
				else if(lap[j]>0 && res[j]!='+')
					res[j] = '?';
			}
		}
	}
	return res;
	
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
