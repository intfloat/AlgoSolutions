#include <queue>
#include <utility>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

const int dir_x[] = {0, 1};
const int dir_y[] = {1, 0};
class Solution {
public:
    int row, col;
    bool check(const vector<vector<int> >& maze) {
        if (maze[0][0] <= 0) return false;
        pair<int, int> target = make_pair(row - 1, col - 1);
        set<pair<int, int> > s;        
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0)); s.insert(make_pair(0, 0));
        while (!q.empty()) {
            pair<int, int> tp = q.front(); q.pop();
            if (tp == target) return true;
            for (int i = 0; i < 2; ++i) {
                int nx = tp.first + dir_x[i];
                int ny = tp.second + dir_y[i];
                if (nx >= row || ny >= col) continue;
                pair<int, int> t = make_pair(nx, ny);
                if (s.find(t) != s.end()) continue;
                if (maze[nx][ny] <= 0) continue;
                q.push(t); s.insert(t);
            }
        }
        return false;
    }

    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int low = 1, up = 1;
        row = dungeon.size(); col = dungeon[0].size();
        for (int i = 0; i < row; ++i) up += abs(dungeon[i][0]);
        for (int i = 1; i < col; ++i) up += abs(dungeon[row - 1][i]);
        while (low < up) {            
            int mid = (low + up) / 2;
            vector<vector<int> > maze = dungeon;
            maze[0][0] = dungeon[0][0] + mid;
            for (int i = 1; i < row; ++i) maze[i][0] = maze[i - 1][0] + dungeon[i][0];
            for (int i = 1; i < col; ++i) maze[0][i] = maze[0][i - 1] + dungeon[0][i];
            for (int i = 1; i < row; ++i)
                for (int j = 1; j < col; ++j) {
                    maze[i][j] = (int)-1e8;
                    if (maze[i][j - 1] > 0) maze[i][j] = max(maze[i][j], maze[i][j - 1]);
                    if (maze[i - 1][j] > 0) maze[i][j] = max(maze[i][j], maze[i - 1][j]);
                    if (maze[i][j] > 0) maze[i][j] += dungeon[i][j];
                }
            if (check(maze)) up = mid;
            else low = mid + 1;
        }
        return low;
    }
};
