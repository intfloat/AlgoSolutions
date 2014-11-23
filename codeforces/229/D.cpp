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
    int row, col, k;
    cin>>row>>col>>k;
    bool visited[55][55];
    memset(visited, false, sizeof(visited));
    int res = 0;
    int counter = 0;
    vector<pair<int, int> > v;
    v.clear();
    for(int i=1; ; i++){
        if(counter >= k) break;
        for(int j=1; j<=i; j++){
            int c = j;
            int r = i-j+1;
            if(c>col || r>row) continue;
            ++counter;
            res += i;
            v.push_back(make_pair(r, c));
            visited[r][c] = true;
            if(counter >= k) break;
        }
    }
    printf("%d\n", res);
    //assert(v.size() < 3000);
    for(int i=v.size()-1; i>=0; i--){
        int r = v[i].first;
        int c = v[i].second;
        //assert(r<55);
        //assert(c<55);
        for(int j=1; j<=c; j++)
            printf("(%d,%d) ", 1, j);
        for(int j=2; j<=r; j++)
            printf("(%d,%d) ", j, c);
        printf("\n");
    }
  	return 0;
}
