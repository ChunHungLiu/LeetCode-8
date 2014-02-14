
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int n = num.size();
        vector<vector<int> > res;
        if (n < 3) return res;
        
        sort(num.begin(), num.end());
        for (int i = 0; i < n-2; ++i) {
            if (i != 0 && num[i] == num[i-1]) continue;

            int left = i+1, right = n-1;
            while (left < right) {
                while (left > i+1 && left < n-1 && num[left] == num[left-1]) ++left;
                while (right < n-1 && right > 0 && num[right] == num[right+1]) --right;
                if (left >= right) break; 
                
                int val = num[i] + num[left] + num[right];

                if (val == 0) {
                    vector<int> x;
                    x.push_back(num[i]); x.push_back(num[left]); x.push_back(num[right]);
                    res.push_back(x);
                    ++left; --right;
                } else if (val > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
        }
        
        return res;
    }
};