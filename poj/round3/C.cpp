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

const int SIZE = 3005;

int getIndex(int number){
    return abs(number)*2+(number < 0);
}

int main(){
    int n, m;
    vector<int> adj[SIZE];
    while(cin>>n>>m){
        for(int i=0; i<SIZE; i++) 
            adj[i].clear();
        for(int i=0; i<m; i++){
            int node1, node2, no1, no2;
            cin>>node1>>node2>>no1>>no2;
            if(no1 == 1){
                node1 = -node1;
                if(no2 == 0) node2 = -node2;
            }
            else if(no1 == 0){
                if(no2 == 0) node2 = -node2;
            }
            adj[getIndex(-node1)].push_back(getIndex(node2));
            adj[getIndex(-node2)].push_back(getIndex(node1));
            //radj[getIndex(node2)].push_back(getIndex(-node1));
            //radj[getIndex(node1)].push_back(getIndex(-node2));
        }
        int res = 0;
        bool flag[SIZE];
        vector<int> goal; goal.clear();
        memset(flag, false, sizeof(flag));
        for(int i=1; i<=n; i++){
            int pos = getIndex(i);
            memset(flag, false, sizeof(flag));
            queue<int> q;
            while(q.empty() == false) q.pop();
            q.push(pos); flag[pos] = true;
            while(q.empty() == false){
                int tmp = q.front(); q.pop();
                int len = adj[tmp].size();
                for(int j=0; j<len; j++){
                    if(flag[adj[tmp][j]]==true) continue;
                    flag[adj[tmp][j]] = true;
                    q.push(adj[tmp][j]);
                }
            }
            if(flag[pos+1] == true){ 
                res++; goal.push_back(i);
            }
        }
        cout<<res<<endl;
        if(res > 0) cout<<goal[0];
        for(int i=1; i<goal.size(); i++)
            cout<<" "<<goal[i];
        cout<<endl;
    }
    return 0;
}

