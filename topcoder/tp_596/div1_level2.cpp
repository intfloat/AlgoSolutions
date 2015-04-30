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

class BitwiseAnd {
public:
    vector<long long> lexSmallest(vector<long long>, int);
};

// it is a great pity, I should use (1LL<<k) rather than (1<<k)...
vector<long long> BitwiseAnd::lexSmallest(vector<long long> subset, int N) {
    bool used[100];
    bool single[100];
    vector<long long> res;
    vector<int> record[100];
    res.clear();
    for(int i=0; i<100; i++) record[i].clear();
    int len = subset.size();
    memset(used, false, sizeof(used));
    memset(single, false, sizeof(single));
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            long long cur = subset[i]&subset[j];
            if(cur == 0) return res;
            for(int k=0; k<60; k++){
                if(((1LL<<k)&cur) > 0){
                    if(used[k] == true) return res;
                    used[k] = true;
                }
            }
        }
    }
    for(int i=0; i<len; i++){
        for(int j=0; j<60; j++){
            if(((1LL<<j)&subset[i])>0) single[j] = true;
            if(((1LL<<j)&subset[i])>0 && used[j]==false)
                record[i].push_back(j);
        }
        if(record[i].size() < (N-len)) return res;
    }
    for(int i=0; i<len; i++) res.push_back(subset[i]);
    bool solution = true;
    for(int i=0; i<N-len; i++){
        int remain = N-len-1-i;
        long long number = 0;
        for(int j=0; j<res.size(); j++){
            int bits = record[j][0];
            record[j].erase(record[j].begin());
            number = number|(1LL<<bits);
            used[bits] = true;
            single[bits] = true;
        }
        solution = true;
        for(int k=0; k<remain; k++){
            solution = false;
            for(int j=0; j<60; j++){
                if(single[j] == false){
                   number = number|(1LL<<j);
                   record[i+len].push_back(j);
                   single[j] = true;
                   solution = true;
                   break;
                }
            }
            if(solution == false){ res.clear(); return res; }
        }
        res.push_back(number);
    }
    sort(res.begin(), res.end());
    return res;
}

//<%:testing-code%>

//Powered by [KawigiEdit] 2.0!

