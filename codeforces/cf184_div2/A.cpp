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
	int k, num, dou;
	bool one=false, two=false, tens=false;
	vector<int> res;
	res.clear();
	cin>>k;
	for(int i=0; i<k; i++){
		cin>>num;
		if(num==0 || num==100)
			res.push_back(num);
		else if(num%10==0 && tens==false){
			res.push_back(num);
			tens = true;
		}
		else if(num>0 && num<10 && one==false){
			res.push_back(num);
			one = true;
		}
		else if(num>10 && num%10!=0 && two==false){
			two = true;
			dou = num;
		}
	}
	
	if(one == false && two == true && tens==false) 
		res.push_back(dou);
		
	cout<<res.size()<<endl;
	for(int i=0; i<res.size(); i++)
		cout<<res[i]<<" ";
	cout<<endl;
	//system("pause");
	return 0;
}
