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

int main(){     
    int b, d;
    string a, c;
    cin>>b>>d;
    cin>>a>>c;
    int alen = a.size();
    int clen = c.size();
    pair<int, int> p[105];
    for(int i=0; i<clen; i++){
        int counter = 0;
        int next = 0;
        int ptr = i;
        for(int j=0; j<alen; j++){
            if(c[ptr] == a[j]){
                ptr = (ptr+1)%clen;
                if(ptr == 0)
                    counter++;
            }
        }
        p[i] = make_pair(ptr, counter);
    }
    
    int cur = 0;
    int res = 0;
    for(int i=0; i<b; i++){
        int next = p[cur].first;
        res += p[cur].second;
        cur = next;
    }
    res = res/d;
    cout<<res<<endl;
    //system("pause");
    return 0;
}
