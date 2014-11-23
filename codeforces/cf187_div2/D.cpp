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
	int b, d;
	string astr, cstr;
	cin>>b>>d;
	cin>>astr>>cstr;
	int alen = astr.size();
	int clen = cstr.size();
	int ptr = 0, ptr1 = 0; 
	int pre = 0, counta[30], countc[30];
	memset(counta, 0, sizeof(counta));
	memset(countc, 0, sizeof(countc));
	int aloop = -1, cloop=0;
	bool solution = true;
	
	for(int i=0; i<alen; i++)
		counta[astr[i]-'a']++;
	for(int i=0; i<clen; i++)
		countc[cstr[i]-'a']++;
	for(int i=0; i<30; i++){
		if(countc[i]>0 && counta[i]==0)
			solution = false;
	}
	
	if(solution==false){
		cout<<0<<endl;
		return 0;
	}
	

	for(int i=0; i<alen; i=(i+1)%alen){
		if(i==0)
			aloop++;
		if(aloop == b)
			break;
		if(ptr==0 && i==0 && cloop>0)
			break;
		if(astr[i] == cstr[ptr]){
			//ptr1++;
			ptr = (ptr+1)%clen;
			if(ptr==0)
				cloop++;			
		}
//		if(ptr==0 && i==0 && cloop>0)
//			break;
	}
	
	if(aloop == b){
		cout<<cloop/d<<endl;
		//system("pause");
		return 0;
	}

	int tmp = b/aloop;
	int remain = b%aloop;
	remain *= alen;
	tmp = tmp*cloop;
	
	int res = 0;
	ptr = 0;
	for(int i=0; i<remain; i++){
		if(astr[i%alen]==cstr[ptr]){
			ptr = (ptr+1)%clen;
			if(ptr==0)
				res++;
		}
	}
	
	res = res+tmp;
	res = res/d;
	cout<<res<<endl;
	
	//system("pause");
	return 0;
}
