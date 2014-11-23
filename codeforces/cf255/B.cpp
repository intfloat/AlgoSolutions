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
	int row, col, k, p;
	int arr[1005][1005];
	scanf("%d%d%d%d", &row, &col, &k, &p);
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			scanf("%d", &arr[i][j]);

    vector<long long> r, c;
    vector<long long> h;
    r.clear(); c.clear(); h.clear();
    
    for(int i=0; i<row; i++) {
    	long long cur = 0;
    	for(int j=0; j<col; j++) cur += arr[i][j];
    	h.push_back(cur);
    }
    make_heap(h.begin(), h.end());    
    for(int i=1; i<=k; i++) {
    	long long mx = h.front();
    	r.push_back(mx);
    	pop_heap(h.begin(), h.end());
    	h.pop_back();
        mx -= col * p;
        h.push_back(mx);
        push_heap(h.begin(), h.end());
    }

    h.clear();
    for(int i=0; i<col; i++) {
    	long long cur = 0;
    	for(int j=0; j<row; j++) cur += arr[j][i];
         h.push_back(cur);
    }
    make_heap(h.begin(), h.end());
    for(int i=1; i<=k; i++) {
    	long long mx = h.front();
    	c.push_back(mx);
    	pop_heap(h.begin(), h.end());
    	h.pop_back();
    	mx -= p * row;
    	h.push_back(mx);
    	push_heap(h.begin(), h.end());
    }
    for(int i=1; i<k; i++) {
    	r[i] += r[i-1];
    	c[i] += c[i-1];
    }

    long long ans = max(r[k-1], c[k-1]);    
    for(int i=1; i<k; i++) {
    	long long tmp = ((long long)i) * (k-i) * p;
    	ans = max(ans, r[i-1]+c[k-i-1]-tmp);
    }
    cout<<ans<<endl;
	return 0;
}

