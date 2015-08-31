#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> point;
const int INF = INT_MAX / 2;
const int dir_x[] = {1, -1, 0, 0, 0, 0};
const int dir_y[] = {0, 0, 1, -1, 0, 0};
const int dir_z[] = {0, 0, 0, 0, 1, -1};
int main() {
    int R, C, H, M;
    scanf("%d %d %d", &R, &C, &H);
    char g[55][55][55];
    point mess;
    FOR(h, H) FOR(r, R) {
        scanf("%s", g[h][r]);
        FOR(c, C) {
            if (g[h][r][c] == '*') {
                mess = make_tuple(r, c, h);
            }
        }
    }
    int steps[55][55][55], x, y, z;
    FOR(i, 55) FOR(j, 55) FOR(k, 55) steps[i][j][k] = INF;
    steps[get<0>(mess)][get<1>(mess)][get<2>(mess)] = 0;
    queue<point> q;
    q.push(mess);
    while (!q.empty()) {
        point tp = q.front(); q.pop();
        x = get<0>(tp), y = get<1>(tp), z = get<2>(tp);
        FOR(i, 6) {
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];
            int nz = z + dir_z[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= H) {
                continue;
            }
            if (g[nz][nx][ny] == '#' || steps[nx][ny][nz] <= steps[x][y][z] + 1) {
                continue;
            }
            steps[nx][ny][nz] = steps[x][y][z] + 1;
            q.push(make_tuple(nx, ny, nz));
        }
    }
    scanf("%d", &M);
    char name[20];
    string res;
    int mn = INF;
    FOR(i, M) {
        scanf("%s %d %d %d", name, &x, &y, &z);
        string cur = name;
        --x; --y; --z;
        if (steps[x][y][z] < mn || (steps[x][y][z] == mn && cur < res)) {
            mn = steps[x][y][z];
            res = cur;
        }
    }
    if (mn == INF) {
        printf("None!\n");
    }
    else {
        printf("%s %d\n", res.c_str(), mn);
    }
    return 0;
}
