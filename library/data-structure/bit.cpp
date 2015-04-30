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
const int MAXN = 1005;
long long f[MAXN];
int n;

// initialize two Fenwick trees
void init(){
    memset(f, 0, sizeof(f));
}

// add val to pos
void update(int pos, long long val){
    if(pos==0) return;
    while(pos <= n){
        f[pos] += val;
        pos += pos&(-pos);
    }
}
// query sum in range [1, pos] in a single Fenwick tree,
// use query(right)-query(left-1), 
// you can get sum of range [left, right]
long long query(int pos){
    long long sum = 0;
    while(pos > 0){
        sum += f[pos];
        pos -= pos&(-pos);
    }
    return sum;
}

int main(){ 
    cin>>n;
    return 0;
}
