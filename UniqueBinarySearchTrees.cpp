class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) { return 1; }
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += numTrees(i-1) * numTrees(n-i);
        }
        
        return sum;
    }
};

class Solution {
public:
    map<int, int> dp;

    int numTrees(int n) {
        if (dp.find(n) == dp.end()) {
            if (n <= 1) { 
                dp[n] = 1; 
                return dp[n]; 
            }
            int sum = 0;
            for (int i = 1; i <= n; ++i) {
                sum += numTrees(i-1) * numTrees(n-i);
            }
            dp[n] = sum;
        }
        
        return dp[n];
    }
};
