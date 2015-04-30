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
    int n, k;
    string road;
    cin>>n>>k;
    cin>>road;
    int cur = 0;
    bool okay = true;
    for(int i=0; i<n; i++){
        if(road[i] == '#')
            cur++;
        else
            cur = 0;
        if(cur >= k){
            okay = false;
            break;
        }
    }
    if(okay == true)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
