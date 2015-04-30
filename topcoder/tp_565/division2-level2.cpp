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

class MonstersValley2 {
public:
    int res, len;
    vector<int> d, p;
    int minimumPrice(vector <int>, vector <int>);
    void rec(int step, int cost, long long sum);
};

void MonstersValley2::rec(int step, int cost, long long sum){
    //boundary of recurrence
    if(step == len){
        res = min(res, cost);
        return;
    }
    if(cost >= res)
        return;
    //can only bribe the monster
    if(sum < d[step]){
        rec(step+1, cost+p[step], sum+d[step]);     
    }
    else{
        rec(step+1, cost, sum);
        rec(step+1, cost+p[step], sum+d[step]);
    }
    return;
}

int MonstersValley2::minimumPrice(vector <int> dread, vector <int> price) {
    d = dread, p = price;
    len = dread.size();
    res = len*2;
    rec(1, price[0], dread[0]);
    return res;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

