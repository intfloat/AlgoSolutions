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
    int n, t;
    set<int> s;
    set<int>::iterator it;
    while(cin>>n) {
        s.clear();
        for(int i=0; i<n; i++) {
            cin>>t;         
            it = s.find(t);
            if (it != s.end()) continue;
            s.insert(t);
            it = s.find(t);
            it++;
            if (it == s.end()) continue;
            else s.erase(it);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}