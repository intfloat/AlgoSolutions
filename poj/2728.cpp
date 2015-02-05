#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;

vector<pair<double, double> > pos;
vector<double> h;

double get_dis(int from, int to, double mid) {
    double len = (pos[from].first - pos[to].first) * (pos[from].first - pos[to].first)
            + (pos[from].second - pos[to].second) * (pos[from].second - pos[to].second);
    double res = -mid * sqrt(len) + fabs(h[from] - h[to]);    
    return res;
}

int main() {
    int n;
    while (cin >> n && n) {
        pos.resize(n); h.resize(n);
        FOR(i, n) {
            cin >> pos[i].first >> pos[i].second >> h[i];            
        }
        double left = 0, right = 10000.0;
        vector<double> dis(n);
        vector<bool> visited(n);
        while (right - left > 1e-6) {
            double mid = (right + left) / 2;            
            double cur = 0;            
            // run prim algorithm to obtain maximum spanning tree
            fill(visited.begin(), visited.end(), false);
            FOR(i, n) dis[i] = get_dis(0, i, mid);
            visited[0] = true;
            FOR(i, n - 1) {
                double mn = 1e10;
                int idx = -1;
                FOR(j, dis.size()) {                    
                    if (!visited[j] && dis[j] < mn) {
                        mn = dis[j];
                        idx = j;
                    }
                }                
                visited[idx] = true;                
                cur += mn;
                FOR(j, dis.size()) {
                    if (!visited[j]) dis[j] = min(dis[j], get_dis(idx, j, mid));
                }
            }    
            if (cur < 0) right = mid;
            else left = mid;
        }
        double res = left;
        cout << fixed << setprecision(3) << res << endl;        
    }
    return 0;
}
