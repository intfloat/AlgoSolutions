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
#include <cassert>
using namespace std;

struct Node{
	int l, r, index;
	Node() {}
	Node(int _l, int _r, int _index) : l(_l), r(_r), index(_index){}
};

const int SIZE = 50005;
int N, L;
int cost[SIZE];
long long s[SIZE];
long long dp[SIZE];
deque<Node> d;

long long get(int j, int pos) {
	if(j > pos) return (long long)1e17;
	long long t1 = s[pos] - s[j-1] + (pos - j) - L;
	long long c1 = dp[j-1] + t1 * t1;	
	return c1;
}

int main() {
	scanf("%d%d", &N, &L);
	cost[0] = 0; dp[0] = 0;
	for(int i=1; i<=N; i++) scanf("%d", cost+i);	
	s[0] = 0;
	for(int i=1; i<=N; i++) s[i] = s[i-1] + cost[i];	
	while(d.empty() == false) d.pop_front();
	d.push_back(Node(1, N, 1));

	for(int i=1; i<=N; i++) {
		dp[i] = get(d.front().index, i);
		if(d.front().l < d.front().r) d.front().l++;
		else d.pop_front();
		while(d.empty() == false) {
			if(get(i+1, d.back().l) <= get(d.back().index, d.back().l))
				d.pop_back();
			else {
				int left = d.back().l;
				int right = d.back().r;
				while(left+1 < right) {
					int mid = (left + right)/2;
					if(get(i+1, mid) <= get(d.back().index, mid)) right = mid - 1;
					else left = mid;
				}
				if(get(i+1, right) > get(d.back().index, right)) d.back().r = right;
				else d.back().r = left;
				if(d.back().r < N) d.push_back(Node(d.back().r+1, N, i+1));
				break;
			}
		}
		if(d.empty()) d.push_back(Node(i+1, N, i+1));
		if(d.back().r < N) d.push_back(Node(d.back().r+1, N, i+1));
		// cout<<i<<" "<<dp[i]<<endl;
	} // end for loop

	cout<<dp[N]<<endl;
	return 0;
}

