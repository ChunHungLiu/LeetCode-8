class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // assume n always >= 3
        int n = num.size();
        sort(num.begin(), num.end());

        int res = 0, diff = INT_MAX, tmp_diff = 0;
        for (int i = 0; i < n-2; ++i) {
            if (i != 0 && num[i] == num[i-1]) continue;
            int left = i+1, right = n-1;
            while (left < right) {
                while (left > i+1 && left < n-1 && num[left] == num[left-1]) ++left;
                while (right < n-1 && right > 0 && num[right] == num[right+1]) --right;
                if (left >= right) break;
                
                int val = num[i] + num[left] + num[right];
                if (val == target) { return target; }
                else if (val < target) {
                    tmp_diff = target - val;
                    ++left;
                } else {
                    tmp_diff = val - target;
                    --right;
                }
                if (tmp_diff < diff) { diff = tmp_diff; res = val; }
            }
        }
        
        return res;
    }
};