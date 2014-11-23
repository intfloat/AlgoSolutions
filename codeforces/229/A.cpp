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
    int n;
    vector<int> row, col;
    row.clear(); col.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        row.push_back(x);
        col.push_back(y);
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    int r1 = unique(row.begin(), row.end())-row.begin();
    int r2 = unique(col.begin(), col.end())-col.begin();
    cout<<min(r1, r2)<<endl;
	return 0;
}
