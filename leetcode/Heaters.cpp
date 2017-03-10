#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.empty()) {
            return 0;
        }
        sort(heaters.begin(), heaters.end());
        int mx = 0;
        for (int i = 0; i < houses.size(); ++i) {
            vector<int>::iterator it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            if (it == heaters.end()) {
                mx = max(mx, houses[i] - heaters.back());
            } else if (it == heaters.begin()) {
                mx = max(mx, heaters[0] - houses[i]);
            } else {
                mx = max(mx, min(*it - houses[i], houses[i] - *(it - 1)));
            }
        }
        return mx;
    }
};

int main() {
    return 0;
}
