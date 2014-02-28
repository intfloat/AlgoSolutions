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
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
using namespace std;

int n;
string maze[105];
int flag[105][105];
const int dir_x[] = {0, 0, -1, -1, 1, 1};
const int dir_y[] = {-1, 1, 0, 1, -1, 0};

bool blueWin(){
    int cur = 1;
    queue<pair<int, int> > q;
    memset(flag, 0, sizeof(flag));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(maze[i][j]=='B' && flag[i][j]==0){
                flag[i][j] = cur;
                while(q.empty() == false) q.pop();
                q.push(make_pair(i, j));
                while(q.empty() == false){
                    pair<int, int> pos = q.front();
                    q.pop();
                    int x = pos.first; int y = pos.second;
                    for(int k=0; k<6; k++){
                        int xx = x+dir_x[k];
                        int yy = y+dir_y[k];
                        if(xx>=n || xx<0 || yy>=n || yy<0) continue;
                        if(maze[xx][yy]!=maze[x][y] || flag[xx][yy]>0) continue;
                        flag[xx][yy] = flag[x][y];
                        q.push(make_pair(xx, yy));
                    }
                }
            }
            cur++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(maze[i][0]=='B' && maze[j][n-1]=='B' 
               && flag[i][0]==flag[j][n-1])
                return true;
        }
    }
    return false;
}
bool redWin(){
    int cur = 1;
    queue<pair<int, int> > q;
    memset(flag, 0, sizeof(flag));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(maze[i][j]=='R' && flag[i][j]==0){
                flag[i][j] = cur;
                while(q.empty() == false) q.pop();
                q.push(make_pair(i, j));
                while(q.empty() == false){
                    pair<int, int> pos = q.front();
                    q.pop();
                    int x = pos.first; int y = pos.second;
                    for(int k=0; k<6; k++){
                        int xx = x+dir_x[k];
                        int yy = y+dir_y[k];
                        if(xx>=n || xx<0 || yy>=n || yy<0) continue;
                        if(maze[xx][yy]!=maze[x][y] || flag[xx][yy]>0) continue;
                        flag[xx][yy] = flag[x][y];
                        q.push(make_pair(xx, yy));
                    }
                }
            }
            cur++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(maze[0][i]=='R' && maze[n-1][j]=='R' 
               && flag[0][i]==flag[n-1][j])
                return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    for(int testCase=1; testCase<=t; testCase++){
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>maze[i];
        int rcnt = 0; int bcnt = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                if(maze[i][j]=='R') rcnt++;
                if(maze[i][j]=='B') bcnt++;
            }
        if(abs(rcnt-bcnt) > 1){
            cout<<"Case #"<<testCase<<": Impossible"<<endl;
            continue;
        }
        bool red = redWin();
        bool blue = blueWin();
        if(red==false && blue==false){
            cout<<"Case #"<<testCase<<": Nobody wins"<<endl;
            continue;
        }
        if((red==true && bcnt>rcnt) 
           || (blue==true && rcnt>bcnt)
           || (red==true && blue==true)){
            cout<<"Case #"<<testCase<<": Impossible"<<endl;
            continue;
        }
        bool multipath = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(multipath == false) break;
                if(red==true && maze[i][j]=='R'){
                    maze[i][j] = '.';
                    multipath = multipath && redWin();
                    maze[i][j] = 'R';
                }
                else if(blue==true && maze[i][j]=='B'){
                    maze[i][j] = '.';
                    multipath = multipath && blueWin();
                    maze[i][j] = 'B';
                }
                if(multipath == false) break;
            }
        }
        if(multipath == true){
            cout<<"Case #"<<testCase<<": Impossible"<<endl;
        }
        else if(red == true)
            cout<<"Case #"<<testCase<<": Red wins"<<endl;
        else if(blue == true)
            cout<<"Case #"<<testCase<<": Blue wins"<<endl;
    }
    return 0;
}
