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

int main(){		
	int n, m;
    int color[105];
    vector<pair<int, int> > v;
    v.clear();
    memset(color, 0, sizeof(color));
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        color[tmp]++;
    }
    for(int i=0; i<105; i++){
        if(color[i] > 0) v.push_back(make_pair(color[i], i));
    }    
    sort(v.begin(), v.end());    
    vector<pair<int, int> > res;
    while (v.size() > 1) {
        // cout << "v[0]: " << v[0].first << endl;        
        for (int i = 0; i < v.size(); ++i) res.push_back(make_pair(v[i].second, v[(i + 1) % v.size()].second));
        for (int i = 0; i < v.size(); ++i) --v[i].first;                    
        while (v.size() >= 1 && v[0].first == 0) v.erase(v.begin());
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) cout << res[i].first << " " << res[i].second << endl;
    assert(v.size() <= 1);
    if (v.size() == 1) {
        for (int i = 0; i < v[0].first; ++i) cout << v[0].second << " " << v[0].second << endl;
    }
    return 0;
}
