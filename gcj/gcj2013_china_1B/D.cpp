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
#define point pair<int, int>
#define x first
#define y second
using namespace std;

const int dir_x[] = {0, 0, -1, 1};
const int dir_y[] = {-1, 1, 0, 0};

int main(){	
    int t;
    cin>>t;
    queue<pair<point, point> > q;
    int maze[105][105];
    bool visited[105][105];
    long long cur[105][105];
    for(int i=1; i<=t; i++){
        int row, col;
        cin>>row>>col;
        memset(cur, 0, sizeof(cur));
        memset(visited, false, sizeof(visited));
        int sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey;
        for(int j=0; j<row; j++)
            for(int k=0; k<col; k++)
                cin>>maze[j][k];
        point p1 = make_pair(sx, sy);
        point p2 = make_pair(0, maze[sx][sy]);
        point goal = make_pair(ex, ey);
        cur[sx][sy] = maze[sx][sy];
        bool solution = false;
        while(q.empty() == false)
            q.pop();

        q.push(make_pair(p1, p2));
        //visited[sx][sy] = true;
        pair<point, point> tmp;
        int step = INT_MAX;
        int res = 0;
        while(q.empty() == false){
            tmp = q.front(); q.pop();
            p1 = tmp.x; p2 = tmp.y;
            visited[p1.x][p1.y] = true;
            if(p2.y < cur[p1.x][p1.y])
                continue;
            if(p1==goal && step==INT_MAX){
                solution = true;
                step = p2.x;
                res = p2.y;
                continue;
            }
            if(p1==goal && p2.x==step){
                res = max(res, p2.y);
                continue;
            }
            for(int j=0; j<4; j++){
                int tx = p1.x + dir_x[j];
                int ty = p1.y + dir_y[j];
                if(tx<0 || tx>=row || ty<0 || ty>=col)
                    continue;
                if(visited[tx][ty]==true || maze[tx][ty]==-1)
                    continue;
                point tp1 = make_pair(tx, ty);
                point tp2 = make_pair(p2.x+1, p2.y+maze[tx][ty]);
                if(p2.y+maze[tx][ty] <= cur[tx][ty])
                    continue;
                //visited[tx][ty] = true;
                q.push(make_pair(tp1, tp2));
                cur[tx][ty] = p2.y+maze[tx][ty];
            }
        }
        if(solution == true)
            cout<<"Case #"<<i<<": "<<res<<endl;      
        else
            cout<<"Case #"<<i<<": Mission Impossible."<<endl;
    }
	return 0;
}
