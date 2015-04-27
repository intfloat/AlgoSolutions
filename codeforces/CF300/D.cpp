#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int N;
    cin >> N;
    vector<string> g(N);
    FOR(i, N) cin >> g[i];
    set<pair<int, int> > s;
    for (int i = -(N - 1); i <= N - 1; ++i)
    for (int j = -(N - 1); j <= N - 1; ++j) {
        if (i == 0 && j == 0) continue;
        s.insert(make_pair(i, j));
    }
    vector<pair<int, int> > piece, att, natt;
    FOR(i, N) FOR(j, N) {
        if (g[i][j] == 'o') piece.push_back(make_pair(i, j));
        else if (g[i][j] == 'x') att.push_back(make_pair(i, j));
        else { 
            // assert(g[i][j] == '.');
            natt.push_back(make_pair(i, j));
        }
    }
    FOR(i, piece.size()) FOR(j, natt.size()) {
        int dr = natt[j].first - piece[i].first;
        int dc = natt[j].second - piece[i].second;
        pair<int, int> t = make_pair(dr, dc);
        if (s.find(t) != s.end()) s.erase(t);
    }
    // cout << "DEBUG2" << endl;
    FOR(i, att.size()) {
        bool ok = false;
        FOR(j, piece.size()) {
            int dr = att[i].first - piece[j].first;
            int dc = att[i].second - piece[j].second;
            if (s.find(make_pair(dr, dc)) != s.end()) {
                ok = true;
                break;
            }
        }
        if (!ok) { cout << "NO" << endl; return 0; }
    }
    vector<string> res(2 * N - 1);
    string row = "";
    FOR(i, 2 * N - 1) row += ".";
    FOR(i, 2 * N - 1) res[i] = row;
    res[N - 1][N - 1] = 'o';
    set<pair<int, int> >::iterator it;
    // cout << "DEBUG1" << endl;    
    for (it = s.begin(); it != s.end(); ++it) {
        int tr = N - 1 + (*it).first;
        int tc = N - 1 + (*it).second;
        // cout << tr << " " << tc << endl;
        res[tr][tc] = 'x';
    }
    cout << "YES" << endl;
    FOR(i, 2 * N - 1) cout << res[i] << endl;
    return 0;
}
