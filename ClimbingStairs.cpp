class Solution {
public:
    map<int, int> dp;
    
    int climbStairs(int n) {
        if (dp.find(n) == dp.end()) {
            if (n <= 2) { dp[n] = n; return dp[n]; }
            dp[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        
        return dp[n];
    }
};