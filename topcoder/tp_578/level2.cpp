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
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MOD 1000000007

using namespace std;

class GooseInZooDivOne {
public:
    int count(vector <string>, int);
};

// Passed system test, very happy~
int GooseInZooDivOne::count(vector <string> field, int dist) {
    int counter = 0;
    int row = field.size();
    int col = field[0].size();
    long long res = 1;
    bool used[55][55];
    bool odd = false;
    memset(used, false, sizeof(used));
    queue<pair<int, int> > qu;
    
    for(int i=0; i<row; i++)
    for(int j=0; j<col; j++){
        if(field[i][j]=='.' || used[i][j]==true)
            continue;
        used[i][j] = true;
        int cur = 1;
        counter++;
        qu.push(make_pair(i, j));
        while(qu.empty() == false){
            pair<int, int> tm = qu.front();
            qu.pop();
            int curx = tm.first;
            int cury = tm.second;
            for(int p=-dist; p<=dist; p++)
            for(int q=-dist; q<=dist; q++){
                if(abs(p)+abs(q) > dist)
                    continue;
                int x = curx+p, y=cury+q;
                if(x<0 || x>=row || y<0 || y>=col)
                    continue;
                if(used[x][y]==true || field[x][y]=='.')
                        continue;
                used[x][y] = true;
                qu.push(make_pair(x, y));
                cur++;
            }
        }
        if(cur%2 == 1)
            odd = true;
    }
    //cout<<"counter: "<<counter<<endl;
    for(int i=0; i<counter-1; i++)
        res = (2*res)%MOD;
    if(odd == false && counter>0)
        res = (2*res)%MOD;
    res = (res-1+MOD)%MOD;
    
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
