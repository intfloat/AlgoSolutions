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
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 100005;
int N, rmq[MAX_N][20];
vector<int> year, rain;

void rmq_init() {
    // memset(rmq, 0, sizeof(rmq));
    FOR(i, N) rmq[i][0] = rain[i];
    for (int i = 1; (1 << i) <= N; ++i) {
        for (int j = 0; j + (1 << i) <= N; ++j) {
            rmq[j][i] = max(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
        }
    }
    return;
}
 
int rmq_query(int l, int r) {
    // cout << l << " " << r << endl;
    // assert(l <= r);
    if (l > r) return -1;
    int k = 0;
    while ((1 << (k + 1)) < (r - l + 1)) ++k;
    return max(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}

int main() {
    int M, X, Y;    
    scanf("%d", &N);
    year.clear(); rain.clear();
    FOR(i, N) { int y, r; scanf("%d%d", &y, &r); year.push_back(y); rain.push_back(r); }
    rmq_init();
    scanf("%d", &M);    
    FOR(i, M) {
        scanf("%d%d", &Y, &X);
        int px = lower_bound(year.begin(), year.end(), X) - year.begin();
        int py = lower_bound(year.begin(), year.end(), Y) - year.begin();
        if (X <= Y) { cout << "true" << endl; continue; }
        if (py >= N - 1 || px == 0) { cout << "maybe" << endl; continue; }
        bool has_y = false;
        if (py < year.size() && year[py] == Y) has_y = true;
        if (px < year.size() && year[px] == X) {            
            if (has_y) {
                // cout << "have both: " << py << " " << px << endl;
                int mx = rmq_query(py + 1, px - 1);
                // cout << "query: " << py + 1 << " " << px << " " << mx << endl;
                if (rain[px] > rain[py] || mx >= rain[px]) { cout << "false" << endl; continue; }
                if (px - py == X - Y) { cout << "true" << endl; continue; }
                else { cout << "maybe" << endl; continue; }
            }
            else {
                int mx = rmq_query(py, px - 1);
                if (mx >= rain[px]) { cout << "false" << endl; continue; }
                else { cout << "maybe" << endl; continue; }
            }
        }
        // value for year X is missing
        else {
            // px = px - 1;
            // if (px < 0) { cout << "maybe" << endl; continue; }            
            if (has_y) {
                int mx = rmq_query(py + 1, px - 1);
                if (rain[py] > mx) { cout << "maybe" << endl; continue; }
                else { cout << "false" << endl; continue; }
            }
            else { cout << "maybe" << endl; continue; }
        }
    }    
    return 0;
}
