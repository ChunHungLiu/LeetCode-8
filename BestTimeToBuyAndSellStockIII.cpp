class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) { return 0; }
        int n = prices.size();
        int left[n], right[n];
        
        for (int i = 0; i < n; ++i) { left[i] = right[i] = 0; }
        
        int cur_min = prices[0], cur_res = 0;
        for (int i = 1; i < n; ++i) {
            cur_min = min(cur_min, prices[i]);
            cur_res = max(cur_res, prices[i]-cur_min);
            left[i] = cur_res;
        }
        
        int cur_max = prices[n-1];
        cur_res = 0;
        for (int i = n-1; i >= 0; --i) {
            cur_max = max(cur_max, prices[i]);
            cur_res = max(cur_res, cur_max-prices[i]);
            right[i] = cur_res;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) { res = max(res, right[i]); }
            else if (i == n-1) { res = max(res, left[i]); }
            else { res = max(res, left[i]+right[i]); }
        }
        
        return res;
    }
};