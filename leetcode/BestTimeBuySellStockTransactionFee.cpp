class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sz = prices.size();
        vector<int> dp_has(sz + 1, 0);
        vector<int> dp_no(sz + 1, 0);
        dp_has[0] = -100000;
        for (int i = 1; i <= prices.size(); ++i) {
            dp_has[i] = max(dp_has[i - 1], dp_no[i - 1] - prices[i - 1] - fee);
            dp_no[i] = max(dp_no[i - 1], dp_has[i - 1] + prices[i - 1]);
        }

        return max(dp_has[sz], dp_no[sz]);
    }
};
