#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

int squared_distance(vector<int>& p1, vector<int>& p2) {
    int dx = p1[0] - p2[0];
    int dy = p1[1] - p2[1];
    return dx * dx + dy * dy;
}

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> dis;
        dis.push_back(squared_distance(p1, p2));
        dis.push_back(squared_distance(p1, p3));
        dis.push_back(squared_distance(p1, p4));
        dis.push_back(squared_distance(p2, p3));
        dis.push_back(squared_distance(p2, p4));
        dis.push_back(squared_distance(p3, p4));
        sort(dis.begin(), dis.end());
        return dis[0] > 0 && dis[0] == dis[3] && dis[4] == dis[5] && 2 * dis[0] == dis[4];
    }
};


int main() {
    Solution solution;
    return 0;
}
