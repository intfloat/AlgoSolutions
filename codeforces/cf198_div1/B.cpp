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
	int arr[100005];
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	set<int> st;
	set<int>::iterator it;
	st.clear();
	for(int i=0; i<n; i++) {
	  st.insert(arr[i]);
	  it=st.find(arr[i]);
	  it++;
	  if(it!=st.end()) st.erase(it);
	}
	cout<<st.size()<<endl;
	//system("pause");
	return 0;
}
