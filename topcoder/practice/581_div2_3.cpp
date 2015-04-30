#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

class TreeUnionDiv2 {
public:
    int res, n, length, counter;
    int g1[10][10], g2[10][10];
    vector<pair<int, int> > v[10];
    bool used[10];
    int connect[10];
    int maximumCycles(vector <string>, vector <string>, int);
    void solve(int cur){
        if(cur == n){
            counter = 0;
            pair<int, int> tmp;
            for(int i=0; i<n; i++)
            for(int j=0; j<v[i].size(); j++){
                tmp = v[i][j];
                int goal = length-2-i;
                int ii = connect[tmp.first];
                int jj = connect[tmp.second];
                if(g2[ii][jj]==goal)
                    counter++;
            }
            res = max(res, counter);
            return;
        }
        for(int i=0; i<n; i++){
            if(used[i]==false){
                used[i]=true;
                connect[cur] = i;
                solve(cur+1);
                used[i]=false;
            }
        }
        return;
    }
};

int TreeUnionDiv2::maximumCycles(vector <string> tree1, vector <string> tree2, int K) {
    if(K == 3)
        return 0;
    memset(used, false, sizeof(used));
    length = K;
    res = 0; 
    for(int i=0; i<10; i++)
    for(int j=0; j<10; j++){
        g1[i][j]=100; g2[i][j]=100;
    }
    for(int i=0; i<tree1.size(); i++)
    for(int j=0; j<tree1[i].size(); j++){
        if(tree1[i][j]=='X')
            g1[i][j]=1;
        if(tree2[i][j]=='X')
            g2[i][j]=1;
    }
    n = tree1.size();
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    for(int kk=0; kk<n; kk++){
        g1[j][kk] = min(g1[j][kk], g1[j][i]+g1[i][kk]);
        g2[j][kk] = min(g2[j][kk], g2[j][i]+g2[i][kk]);
    }
    
    
    for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++){
        if(g1[i][j]<10)
            v[g1[i][j]].push_back(make_pair(i, j));     
    }
    
    solve(0);
    
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
