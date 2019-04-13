class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int mx = candies.size() / 2;
        sort(candies.begin(), candies.end());
        int diff = unique(candies.begin(), candies.end()) - candies.begin();
        return min(mx, diff);
    }
};