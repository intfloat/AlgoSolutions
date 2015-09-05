#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
struct Edge {
    int x1, y1, x2, y2;
    Edge(int _x1, int _y1, int _x2, int _y2): x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};
vector<bool> ok;
inline int get(vector<Edge>& arr, int px, int py) {
    double yy = -1e6;
    int ret = -1;
    FOR(i, arr.size()) {
        if (ok[i] && px >= arr[i].x1 && px <= arr[i].x2) {
            double val = (double)(px - arr[i].x1) * (double)(arr[i].y2 - arr[i].y1) / (double)(arr[i].x2 - arr[i].x1) + arr[i].y1;
            if (val > yy && val < py) {
                yy = val;
                ret = i;
            }
        }
    }
    return ret;
}
int main() {
    int px, N, py = (int)(1e6);
    int x1, x2, y1, y2;
    scanf("%d %d", &px, &N);
    vector<Edge> arr;
    ok.resize(N);
    fill(ok.begin(), ok.end(), true);
    FOR(i, N) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        arr.push_back(Edge(x1, y1, x2, y2));
    }
    while (true) {
        int idx = get(arr, px, py);
        if (idx < 0) break;
        ok[idx] = false;
        if (arr[idx].y1 < arr[idx].y2) {
            px = arr[idx].x1;
            py = arr[idx].y1;
        }
        else {
            px = arr[idx].x2;
            py = arr[idx].y2;
        }
    }
    printf("%d\n", px);
    return 0;
}
