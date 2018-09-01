#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<double> prob;
    vector<vector<int> > rects;
public:
    Solution(vector<vector<int> > rects) {
        prob.push_back(0.0);
        int tot = 0;
        for (vector<int>& rect : rects) {
            tot += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
        }
        for (vector<int>& rect : rects) {
            double delta = 1.0 * (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1) / tot;
            prob.push_back(prob.back() + delta);
        }
        this->rects = rects;
    }

    vector<int> pick() {
        double rnd = rand() / (double)RAND_MAX;
        vector<int> res;
        int i = lower_bound(this->prob.begin(), this->prob.end(), rnd) - this->prob.begin();
        double scale_p = (rnd - this->prob[i - 1]) / (this->prob[i] - this->prob[i - 1]);
        vector<int>& rect = this->rects[i - 1];
        int idx = floor(scale_p * (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
        int x = rect[0] + idx % (rect[2] - rect[0] + 1);
        int y = rect[1] + idx / (rect[2] - rect[0] + 1);
        res.push_back(x);
        res.push_back(y);
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
