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
	int n1=0, n2=0;
	string a, b;
	cin>>a>>b;
	int len1=a.size();
	int len2=b.size();
	for(int i=0; i<len1; i++){
		if(a[i]=='1')
			n1++;
	}
	for(int i=0; i<len2; i++){
		if(b[i]=='1')
			n2++;
	}
	bool solution = false;
	if(n1%2==1 && (n1+1)>=n2)
		solution=true;
	else if(n1%2==0 && n1>=n2)
		solution=true;
	if(solution==false)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	//system("pause");
	return 0;
}
