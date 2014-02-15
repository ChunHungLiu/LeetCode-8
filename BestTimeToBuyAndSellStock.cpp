class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) { return 0; }
        int cur_min = INT_MAX, res = INT_MIN;
        
        for (int i = 0; i < prices.size(); ++i) {
            cur_min = min(cur_min, prices[i]);
            res = max(res, prices[i] - cur_min);
        }
        
        return res;
    }
};