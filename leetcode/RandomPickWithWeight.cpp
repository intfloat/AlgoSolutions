
class Solution {
private:
    vector<double> p;
public:
    Solution(vector<int> w) {
        this->p.resize(w.size());
        int sm = accumulate(w.begin(), w.end(), 0);
        for (int i = 0; i < (int)w.size(); ++i) {
            if (i > 0) {
                this->p[i] = this->p[i - 1] + 1.0 * w[i] / sm;
            } else {
                this->p[i] = 1.0 * w[i] / sm;
            }
        }
    }

    int pickIndex() {
        double rnd = 1.0 * rand() / RAND_MAX;
        int idx = lower_bound(this->p.begin(), this->p.end(), rnd) - this->p.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
