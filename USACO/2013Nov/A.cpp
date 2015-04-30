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
string tmp;
vector<string> alpha[500];
int n, K;
long long radix[500];
int cur = 0;
int total = 0;
vector<string> v[500];
vector<string> res;

int getIndex(int cur){
    int len = alpha[cur].size();
    for(int i=0; i<len; i++){
        if(tmp==alpha[cur][i]) return i;
    }
    return -1;
}

bool isLarger(vector<string> str1, vector<string> str2){
    int len = str1.size();
    for(int i=0; i<len; i++){
        if(str1[i] > str2[i]) return true;
        if(str1[i] < str2[i]) return false;
    }
    return false;
}

void incre(){
    int ptr = total-1;
    while(true){
        tmp = res[ptr];
        int t = getIndex(ptr);
        if(t+1 < alpha[ptr].size()){
            res[ptr] = alpha[ptr][t+1];
            break;
        }
        else{
            res[ptr] = alpha[ptr][0];
            ptr--;
        }
    }
    return;
}

int main(){
    freopen("nocow.in", "r", stdin);
    freopen("nocow.out", "w", stdout);
    for(int i=0; i<500; i++){
       alpha[i].clear(); v[i].clear();
    }
    cin>>n>>K;
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++) cin>>tmp;
        cur = 0;
        while(cin>>tmp){
            if(tmp == "cow.")
                break;
            int index = getIndex(cur);
            v[i].push_back(tmp);
            if(index < 0) alpha[cur].push_back(tmp);
            cur++;
        }
        total = max(total, cur);
    }
    for(int i=0; i<total; i++)
        sort(alpha[i].begin(), alpha[i].end());
    radix[total-1] = 1;
    for(int i=total-2; i>=0; i--) 
        radix[i] = radix[i+1]*(alpha[i+1].size());    
    long long num = K-1;
    res.clear();
    for(int i=0; i<total; i++){
        res.push_back(alpha[i][(num/radix[i])]);
        num = num%radix[i];
    }
    bool visited[500];
    memset(visited, false, sizeof(visited));
    bool solution = false;
    while(solution == false){
        solution = true;
        for(int i=0; i<n; i++){
            if(visited[i] == false){
                if(isLarger(v[i], res)==false){
                    visited[i] = true;
                    solution = false;
                    incre();
                }
            }
        }
    }
    cout<<res[0];
    for(int i=1; i<total; i++) cout<<" "<<res[i];
    cout<<endl;
    return 0;
}
