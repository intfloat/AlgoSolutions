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

// MAXN is the number of possible largest elements
const int MAXN = 1005;
int parent[MAXN], rank[MAXN];
int numberOfSet;
// N is the number of elements
int N;

// initialize the data structure, N disjoint set 0..N-1
void init(){
    numberOfSet = N;
    for(int i=0; i<N; i++){
        parent[i] = i;
        rank[i] = 1;
    }
}

// find root of a specific element indexed p
int find(int p){
    // without path compression
    //while(p != parent[p]) p = parent[p];
    //return p;
    //
    // with path compression
    if(p == parent[p]) return p;
    parent[p] = find(parent[p]);
    return parent[p];
}

// if two elements are in the same set
bool connected(int p, int q){
    return (find(p) == find(q));
}

// merge two sets
void merge(int p, int q){
    int rootP = find(p);
    int rootQ = find(q);
    if(rootP == rootQ) return;
    if(rank[rootP] < rank[rootQ]){
        parent[rootP] = rootQ;
        rank[rootQ] += rank[rootP];
    }
    else{
        parent[rootQ] = rootP;
        rank[rootP] += rank[rootQ];
    }
    --numberOfSet;
}

int main(){
    cin>>N;
    init();
    for(int i=0; i<N; i++){
        int x, y;
        cout<<"enter two numbers to merge:";
        cin>>x>>y;
        merge(x, y);
        cout<<"current parents: "<<endl;
        for(int j=0; j<N; j++) cout<<find(j)<<" ";
        cout<<endl;
        cout<<"Number of disjoint sets: "<<numberOfSet<<endl;
    }
	return 0;
}
