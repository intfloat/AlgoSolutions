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

class EelAndRabbit {
public:
    int getmax(vector <int>, vector <int>);
};

int EelAndRabbit::getmax(vector <int> l, vector <int> t) {
    int len = l.size();
    vector<int> v;
    pair<int, int> fish[55];
    for(int i=0; i<len; i++){
        fish[i] = make_pair(t[i], t[i]+l[i]);
        v.push_back(t[i]);
        v.push_back(t[i]+l[i]);
    }
    sort(v.begin(), v.end());
    int res = 0;
    int vlen = v.size();
    for(int i=0; i<vlen; i++)
    for(int j=i+1; j<vlen; j++){
        int tmp = 0;
        for(int k=0; k<len; k++){
            if(v[i]>=fish[k].first && v[i]<=fish[k].second)
                tmp++;
            else if(v[j]>=fish[k].first && v[j]<=fish[k].second)
                tmp++;
        }
        res = max(tmp, res);
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
