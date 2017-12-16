class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int last = -1;
        for (int i = 0; i < timeSeries.size(); ++i) {
            if (timeSeries[i] > last) {
                res += duration;
            } else {
                res += timeSeries[i] + duration - last;
            }
            last = timeSeries[i] + duration;
        }
        return res;
    }
};
