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

int main() {
    int n;
    while(cin>>n) {
        vector<pair<pair<int, int>, int> > p;
        p.clear();
        for(int i=0; i<n; i++) {
            int st, ed, val;
            cin>>st>>ed>>val;
            p.push_back(make_pair(make_pair(ed, st), val));
        }
        sort(p.begin(), p.end());
        int dp[10005];
        memset(dp, 0, sizeof(dp));
        dp[0] = p[0].second;
        for(int i=1; i<n; i++) {
            dp[i] = dp[i-1];
            int cur = p[i].first.second;
            int left = 0;
            int right = i-1;
            // binary search
            // plus 1 to avoid infinite loop at boundary
            while(left+1 < right) {
                int mid = (left+right)/2;
                int t = p[mid].first.first;
                if(t == cur) {
                    left = right = mid;
                    break;
                }
                else if(t > cur) right = mid - 1;
                else if (t < cur) left = mid;
            }
            if (left==0 && p[0].first.first>cur){
                // can only choose this one
                dp[i] = max(dp[i], p[i].second);
                continue;
            }
            // at most 2 iterations
            for(int j=right; j>=left; j--){
                if(p[j].first.first <= cur) {
                    dp[i] = max(dp[i], dp[j]+p[i].second);
                    break;
                }
            }
        }
        cout<<dp[n-1]<<endl;
    } // end while loop
    return 0;
}


