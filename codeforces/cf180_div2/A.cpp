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

int main(){	
	string str;
	int n;
	int s, t;
	cin>>n;
	cin>>str;
	int left=-1, right=-1;
	for(int i=n-1; i>=0; i--){
		if(str[i]=='L' && left==-1)
			left = i;
		if(str[i]=='R' && right==-1)
			right = i;
	}
	if(left>=0 && right>=0){
		s=left;
		t=right+1;
	}
	if(left < 0){
		for(int i=0; i<n; i++){
			if(str[i]=='R'){
				s=i;
				break;
			}
		}
		t=right+1;
	}
	if(right<0){
		s=left;
		for(int i=0; i<n; i++){
			if(str[i]=='L'){
				t = i-1;
				break;
			}
		}
	}
	cout<<s+1<<" "<<t+1<<endl;
	//system("pause");
	return 0;
}
