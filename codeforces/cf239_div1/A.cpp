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
	int a, b;	
	cin>>a>>b;
	if(a>b) swap(a, b);	
	for(int i=1; i<=a; i++){
		for(int j=i; j<=a; j++){
			int tmp = i*i+j*j;
			if(tmp > a*a) break;
			if(tmp==a*a){
				int g = __gcd(i, j);
				int ti = i/g;
				int tj = j/g;
				int tt = ti*ti+tj*tj;
				for(int k=1; ;k++){
					int t = k*k*tt;
					if(t>b*b) break;
					if(t==b*b){
						cout<<"YES"<<endl;
						cout<<"0 0"<<endl;
						cout<<i<<" "<<j<<endl;
						// forget to see if third edge is parallel to axis T_T
						if(k*ti != j)
							cout<<(-k*tj)<<" "<<k*ti<<endl;
						else cout<<(k*tj)<<" "<<(-k*ti)<<endl;
						return 0;
					}
				}
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
