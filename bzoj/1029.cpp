/**************************************************************
    Problem: 1029
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:396 ms
    Memory:4352 kb
****************************************************************/
 
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
 
typedef long long ll;
using namespace std;
 
int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++i) {
        int t, deadline;
        scanf("%d%d", &t, &deadline);
        v.push_back(make_pair(deadline, t));        
    }
    sort(v.begin(), v.end());
    int now = 0;
    vector<int> res;
    vector<pair<int, int> >::iterator it = v.begin();
    for (; it != v.end(); ++it) {
        // cout << "heap size: " << res.size() << endl;
        pair<int, int> cur = *it;
        if (now + cur.second <= cur.first) {
            res.push_back(cur.second);
            push_heap(res.begin(), res.end());
            now += cur.second;
        }
        else {
            if (res.empty()) continue;
            if (res.front() > cur.second) {
                // update current time
                now = now - res.front() + cur.second;
                pop_heap(res.begin(), res.end());
                res.pop_back();
                res.push_back(cur.second);
                push_heap(res.begin(), res.end());
            }
        }
    }
    printf("%d\n", res.size());
    return 0;
}
