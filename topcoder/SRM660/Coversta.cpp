#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef pair<int, int> point;
class Coversta {
public:
    vector<int> dx, dy;
    map<point, int> cc;
    int row, col;
    int place(vector <string>, vector <int>, vector <int>);
    int compute(vector<string>& a, int i, int j) {
        if (cc.find(make_pair(i, j)) != cc.end()) return cc[make_pair(i, j)];
        int nr, nc, res = 0;
        FOR(idx, dx.size()) {
            nr = i + dx[idx]; nc = j + dy[idx];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
            res += a[nr][nc] - '0';
        }
        cc[make_pair(i, j)] = res;
        return res;
    }
};

int Coversta::place(vector <string> a, vector <int> x, vector <int> y) {
    row = a.size(), col = a[0].size();
    dx = x; dy = y;
    vector<pair<int, point> > arr;
    FOR(i, row) FOR(j, col) arr.push_back(make_pair(compute(a, i, j), make_pair(i, j)));
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    int res = 0, up, nr, nc;
    map<point, int> mp;
    FOR(i, row) FOR(j, col) {
        int val = compute(a, i, j);
        point cur = make_pair(i, j);
        mp.clear();
        FOR(p, dx.size()) FOR(q, dx.size()) {
            nr = i + dx[p];
            nc = j + dy[p];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
            mp[make_pair(nr - dx[q], nc - dy[q])] += a[nr][nc] - '0';
        }
        up = min(mp.size() + 5, arr.size());
        int mx = 0;
        FOR(p, up) {
            if (arr[p].second == cur) continue;
            if (mp.find(arr[p].second) == mp.end()) {
                mx = max(mx,  compute(a, arr[p].second.first, arr[p].second.second));
            }
            else {
                mx = max(mx, compute(a, arr[p].second.first, arr[p].second.second) - mp[arr[p].second]);
            }
        }
        val += mx;
        res = max(res, val);
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
