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
#include <queue> 
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

int main(){
	int n, m, q;
	cin>>n;
	for(int i=0; i<n; i++){
		string str;
		queue<int> res;		
		cin>>str>>m>>q;
		int len = str.size();
		int adder = 0;
		for(int j=0; j<m; j++)
			adder += str[j]-'a'+1;
		if(adder == q)
			res.push(0);
		for(int j=m; j<len; j++){
			adder += (str[j]-str[j-m]);
			if(adder == q)
				res.push(j-m+1);
		}
		cout<<res.size()<<endl;
		while(res.empty()==false){
			int tmp = res.front();
			res.pop();
			cout<<str.substr(tmp, m)<<endl;
		}		
	}
	system("pause");
	return 0;
}
