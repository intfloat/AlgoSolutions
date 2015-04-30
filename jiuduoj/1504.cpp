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

bool cmp(string a, string b) {
    int len = min(a.size(), b.size());
    for(int i=0; i<len; i++) {
        if(a[i]!=b[i]) return a[i]<b[i];
    }
    if(a+b < b+a) return true;
    else return false;
}

int main() {
    int m;
    while(cin>>m) {
        vector<string> v;
        v.clear();
        for(int i=0; i<m; i++) {
            string s;
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(), v.end(), cmp);
        string res = "";
        for(int i=0; i<m; i++) res += v[i];
        cout<<res<<endl;
    }
    return 0;
}
