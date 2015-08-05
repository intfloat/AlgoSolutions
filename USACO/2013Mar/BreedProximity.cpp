#include <vector>
#include <list>
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

struct Node{
    int pos;
    int id;
};
Node node[50005];

//sorting
int cmp(const void *ele1, const void *ele2){
    Node* p1=(Node *)ele1;
    Node* p2=(Node *)ele2;
    if((p1->id) == (p2->id))
        return (p1->pos)-(p2->pos);
    else return (p1->id)-(p2->id);
}

int main(){
    freopen("proximity.in", "r", stdin);
    freopen("proximity.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>node[i].id;
        node[i].pos = i;
    }
    qsort(node, n, sizeof(Node), cmp);
    int res = -1;
    int last = -1;
    int large=0, small=0;
    for(int i=n-1; i>0; i--){
        if(res >= node[i].id)
            break;
        if(node[i].id == node[i-1].id){
            if(abs(node[i].pos-node[i-1].pos) <= k)
                res = max(res, node[i].id);
        }
    }
    cout<<res<<endl;
    //system("pause");
    return 0;
}
