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
#include <cstdlib>
#include <ctime>

using namespace std;

class SpecialCells {
public:
    int guess(vector <int>, vector <int>);
};

// unfortunately, randomized algorithm failed system test...
int SpecialCells::guess(vector <int> x, vector <int> y) {
    clock_t start = clock();
    set<pair<int, int> > s;
    s.clear();
    int len = x.size();
    int res = len+10;
    for(int i=0; i<len; i++) s.insert(make_pair(x[i], y[i]));
    while((clock()-start)<1500){
        random_shuffle(x.begin(), x.end());
        set<pair<int, int> > tmp;
        tmp.clear();
        int cur = 0;
        for(int i=0; i<len; i++){
            if(s.find(make_pair(x[i], y[i]))!=s.end()) ++cur;
            tmp.insert(make_pair(x[i], y[i]));
        }
        if(tmp.size()<len) continue;
        res = min(res, cur);
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!