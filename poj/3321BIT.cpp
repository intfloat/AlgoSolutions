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

struct Apple{
    int first;
    int second;
    int value;
};
Apple apple[200000];
vector<int> v[200005];
int c[200100];
int lowbit[200100];
int n, m;
int ptr;

// Query sum of first right elements
int query(int right){
    int res = 0;
    while(right > 0){
        res += c[right];
        right -= lowbit[right];
    }
    return res;
}

// Modify one value
void modify(int index, int value){
    while(index <= 2*n){
        c[index] += value;
        index += lowbit[index];
    }
    return;
}

// Depth first search, current node and its parent
void dfs(int cur, int parent){
    apple[cur].first = ptr;
    ptr++;
    int length = v[cur].size();
    // Visit its children
    for(int i=0; i<length; i++){
        // Can revisit its parent
        //if(v[cur][i] != parent)
            dfs(v[cur][i], cur);
    }
    apple[cur].second = ptr;
    ptr++;
    return;
}

int main(){ 
    int x, y;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        scanf("%d%d", &x, &y);
        //v[x].push_back(y);
        v[y].push_back(x);
    }
    // Initialize apples
    for(int i=1; i<=n; i++){
        apple[i].first = -1;
        apple[i].second = -1;
        apple[i].value = 1;     
    }
    for(int i=1; i<=2*n; i++){
        lowbit[i] = i&(-i);
        c[i] = lowbit[i];
    }
    ptr = 1; 
    // Current node and its parent node
    dfs(1, -1);
    // Get query numbers
    scanf("%d", &m);
    int tmp;
    // Response to every query
    for(int i=0; i<m; i++){
        char command[10];
        scanf("%s", command);
        scanf("%d", &tmp);
        if(command[0] == 'C'){
            if(apple[tmp].value == 0){
                modify(apple[tmp].first, 1);
                modify(apple[tmp].second, 1);
                apple[tmp].value = 1;
            }
            else{
                modify(apple[tmp].first, -1);
                modify(apple[tmp].second, -1);
                apple[tmp].value = 0;
            }
        }
        else{
            int res1 = query(apple[tmp].second);
            int res2 = query(apple[tmp].first);
            printf("%d\n", (res1 - res2 + apple[tmp].value)/2);     
        }
    }
    system("pause");
    return 0;
}
