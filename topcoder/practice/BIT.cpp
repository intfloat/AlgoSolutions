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

int len, tree[105];
// basic functions for binary indexed tree
void update(int pos, int value){
    while(i<=len){
        tree[i] += value;
        i += (i&(-i));
    }
    return;
}

int query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&(-pos));
    }
    return sum;
}

int main(){	
    cin>>len;
	return 0;
}
