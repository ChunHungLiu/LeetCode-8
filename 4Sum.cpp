class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        sort(num.begin(), num.end());
        
        vector<vector<int> > res;
        for (int i = 0; i < n-3; ++i) {
            if (i != 0 && num[i] == num[i-1]) continue;
            for (int j = i+1; j < n-2; ++j) {
                if (j != i+1 && num[j] == num[j-1]) continue;
                int left = j+1, right = n-1;
                while (left < right) {
                    while (left > j+1 && left < n-1 && num[left] == num[left-1]) ++left;
                    while (right < n-1 && right > 0 && num[right] == num[right+1]) --right;
                    if (left >= right) break;
                    
                    int val = num[i] + num[j] + num[left] + num[right];
                    if (val == target) {
                        vector<int> x;
                        x.push_back(num[i]); x.push_back(num[j]); x.push_back(num[left]); x.push_back(num[right]);
                        res.push_back(x);
                        ++left; --right;
                    } else if (val < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        
        return res;
    }
};