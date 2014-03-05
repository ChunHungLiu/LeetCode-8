class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        int permCount = 1;
        for (int i = 0; i < n; ++i) { nums[i] = i+1; permCount *= (i+1); }
        
        // change k from (1,n) to (0,n-1) to get the index
        k--;
        string res;
        for (int i = n; i > 0; --i) {
            permCount = permCount / i;
            int choosed = k / permCount;
            res.push_back('0'+nums[choosed]);
            for (int j = choosed; j < i; ++j) {
                nums[j]=nums[j+1]; // shift right
            }
            k = k % permCount;
        }
        
        return res;
    }
};