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

typedef pair<long long, long long> point;
// runtime error, but I think it is quite right....
int main() {
    long long m, d;
    cin>>m>>d;  
    point *v = new point[200005];
    int ptr = -1;
    long long t = 0;    
    long long total = 0;    
    for(int i=0; i<m; i++) {
        string c;
        long long num;
        cin>>c>>num;
        if (c[0] == 'Q') {          
            if(ptr < 0) {
                cout<<0<<endl;
                t = 0;
                continue;
            }
            // binary search
            int left = 0;
            int right = ptr;
            while(left < right) {
                int mid = (left + right) / 2;
                if(v[mid].second < total-num) left = mid + 1;
                else right = mid;
            }
            t = v[left].first;
            cout<<v[left].first<<endl;
        }
        else if(c[0] == 'A'){           
            num %= d;
            num = (num + t)%d;
            while(ptr>=0) {
                if(v[ptr].first > num) break;
                --ptr;
            }
            ++ptr;
            v[ptr].first = num;
            v[ptr].second = total;
            ++total;
        }
    }
    return 0;
}
