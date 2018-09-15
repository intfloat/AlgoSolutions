#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int row, col;
    set<pair<int, int> > ones;
    vector<pair<int, int> > zeros;
    vector<pair<int, int> > chosen;
    bool large_matrix;
    int get_rand(int mx) {
        double p = rand() / (double)RAND_MAX;
        return floor(p * mx);
    }
public:
    Solution(int n_rows, int n_cols) {
        this->row = n_rows;
        this->col = n_cols;
        this->large_matrix = (n_rows * n_cols) > 3000;
        if (!this->large_matrix) {
            for (int i = 0; i < n_rows; ++i) {
                for (int j = 0; j < n_cols; ++j) {
                    this->zeros.push_back({i, j});
                }
            }
        }
    }

    vector<int> flip() {
        vector<int> ret;
        if (!this->large_matrix) {
            int idx = get_rand(this->zeros.size());
            ret.push_back(this->zeros[idx].first);
            ret.push_back(this->zeros[idx].second);
            this->chosen.push_back(this->zeros[idx]);
            this->zeros.erase(this->zeros.begin() + idx);
        } else {
            while (true) {
                int idx = get_rand(this->row * this->col);
                pair<int, int> p = {idx / this->col, idx % this->col};
                if (this->ones.find(p) == this->ones.end()) {
                    this->ones.insert(p);
                    ret.push_back(p.first);
                    ret.push_back(p.second);
                    break;
                }
            }
        }
        return ret;
    }

    void reset() {
        if (!this->large_matrix) {
            for (auto& p : this->chosen) {
                this->zeros.push_back(p);
            }
            this->chosen.clear();
        } else {
            this->ones.clear();
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
