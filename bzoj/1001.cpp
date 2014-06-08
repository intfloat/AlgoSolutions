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

int row, col;
const int UP = 0;
const int DOWN = 1;
const int S = 0;
const int SIZE = 150*150;
int head[3*SIZE], node[6*SIZE], cost[6*SIZE], next[6*SIZE];
int cur = 0;
int T = -1;
// get index given position in original graph
int get(int r, int c, int pos) {
    int tmp = 1 + 2*r*(col-1) + c;
    if (pos == DOWN) tmp += (col - 1);
    return min(tmp, T);
}

// use a implicit linked list to represent a graph
void add(int a, int b, int v){
    node[cur] = b;
    cost[cur] = v;
    next[cur] = head[a];
    head[a] = cur;
    ++cur;
    node[cur] = a;
    cost[cur] = v;
    next[cur] = head[b];
    head[b] = cur;
    ++cur;
}

int spfa() {
    int d[3*SIZE];
    bool inq[3*SIZE];    // if current vertex is in queue
    for(int i=0; i<3*SIZE; i++) {
        d[i] = (int)1e8;
        inq[i] = false;
    }
    queue<int> q;
    while(q.empty()==false) q.pop();
    d[S] = 0;
    inq[S] = true;
    q.push(S);
    while(q.empty() == false) {
        int t = q.front();
        q.pop();
        inq[t] = false;
        for(int i=head[t]; i>=0; i=next[i]) {
            if(d[node[i]] > d[t]+cost[i]) {
                d[node[i]] = d[t] + cost[i];
                if(inq[node[i]] == false) {
                    inq[node[i]] = true;
                    q.push(node[i]);
                }
            }
        } // end for loop
    } // end while loop
    return d[T];
}

int main(){
    scanf("%d%d", &row, &col);
    if(row==1 && col==1) { printf("0\n"); return 0; }
    // special case
    if(row==1 || col==1) {
        int res = INT_MAX/2;
        for(int i=0; i<max(row, col)-1; i++) {
            int tmp;
            scanf("%d", &tmp);
            res = min(res, tmp);
        }
        printf("%d\n", res);
        return 0;
    }
    T = 2*(row-1)*(col-1) + 1;
    for(int i=0; i<3*SIZE; i++) head[i] = -1;
    // for(int i=0; i<6*SIZE; i++) next[i] = -1;
    int tc;
    // first part
    for(int i=0; i<row; i++) {
        for(int j=0; j<col-1; j++) {            
            scanf("%d", &tc);
            if(i == 0) add(S, get(0, j, UP), tc);
            else if(i == row-1) add(T, get(row-2, j, DOWN), tc);
            else add(get(i-1, j, DOWN), get(i, j, UP), tc);
        }
    }
    // second part
    for(int i=0; i<row-1; i++) {
        for(int j=0; j<col; j++) {
            scanf("%d", &tc);
            if(j==0) add(T, get(i, 0, DOWN), tc);
            else if(j==col-1) add(S, get(i, col-2, UP), tc);
            else add(get(i, j-1, UP), get(i, j, DOWN), tc);
        }
    }
    // thrid part
    for(int i=0; i<row-1; i++) {
        for(int j=0; j<col-1; j++) {
            scanf("%d", &tc);
            add(get(i, j, UP), get(i, j, DOWN), tc);
        }
    }

    printf("%d\n", spfa());
    return 0;
}
