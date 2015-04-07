#include <vector>
#include <list>
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
using namespace std;

int main(){
	freopen("cowrace.in", "r", stdin);
	freopen("cowrace.out", "w", stdout);
	int n, m, t;
	//speed and time
	pair<int, int> node1[1005], node2[1005];
	int res = 0;
	cin>>n>>m;
	//total time
	t = 0;
	int leader = -1;
	for(int i=0; i<n; i++){
		cin>>node1[i].first>>node1[i].second;
		t += node1[i].second;
	}
	//cout<<"t: "<<t<<endl;
	for(int i=0; i<m; i++)
		cin>>node2[i].first>>node2[i].second;
	int pos1 = 0, ptr1 = 0;
	int pos2 = 0, ptr2 = 0;
	for(int i=1; i<=t; i++){
		if(node1[ptr1].second == 0)
			ptr1++;						
		node1[ptr1].second--;
		pos1 += node1[ptr1].first;
		
		//second cow
		if(node2[ptr2].second == 0)
			ptr2++;
		node2[ptr2].second--;
		pos2 += node2[ptr2].first;
		//cout<<"pos1: "<<pos1<<" pos2: "<<pos2<<endl;
		if(leader == -1){
			if(pos1 > pos2)
				leader = 1;
			else if(pos1 < pos2)
				leader = 2;
		}
		else if(leader == 1){
			if(pos2 > pos1){
				res++;
				leader = 2;
			}			
		}
		else if(leader == 2){
			if(pos1 > pos2){
				res++;
				leader = 1;
			}
		}//end else if
		//cout<<"leader: "<<leader<<endl;
	}//end for loop
	cout<<res<<endl;
	//system("pause");
	return 0;
}
