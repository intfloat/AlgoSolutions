#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    double radius, x_center, y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }

    vector<double> randPoint() {
        double x, y;
        while (true) {
            x = 2.0 * rand() / (double)RAND_MAX - 1.0;
            y = 2.0 * rand() / (double)RAND_MAX - 1.0;
            if (x * x + y * y <= 1.0) {
                break;
            }
        }
        vector<double> res;
        res.push_back(x * this->radius + this->x_center);
        res.push_back(y * this->radius + this->y_center);
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */

 int main() {
    Solution sol(1.0, 1.0, 1.0);
    return 0;
 }