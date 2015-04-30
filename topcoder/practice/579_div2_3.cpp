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

class MarblePositioning {
public:
    int len;
    double res;
    bool used[10];
    vector<int> r;
    double record[10];
    double totalWidth(vector <int>);
    void solve(double cur, int n, int pre){
        if(n==len){
            res = min(res, cur);
            return;
        }
        
        for(int i=0; i<len; i++){
            if(used[i] == true)
                continue;
            used[i]=true;
            double tmp = 0;
            for(int j=0; j<len; j++){
                if(used[j]==false || i==j)
                    continue;
                tmp = max(tmp, record[j]+2.0*sqrt(1.0*r[i]*r[j]));
            }
            record[i] = tmp;
            solve(tmp, n+1, i);         
            used[i]=false;
        }
        return;
    }
};

double MarblePositioning::totalWidth(vector <int> radius) {
    len = radius.size();
    r = radius;
    res = 999999999999LL;
    memset(used, false, sizeof(used));
    memset(record, 0, sizeof(record));
    solve(0, 0, -1);
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
