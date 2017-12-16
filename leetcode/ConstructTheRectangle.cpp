class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = (int)sqrt(area);
        vector<int> res;
        for (int i = w; i >= 1; --i) {
            if (area % i == 0) {
                res.push_back(area / i);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};
