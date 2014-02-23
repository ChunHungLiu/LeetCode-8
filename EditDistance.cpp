class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (m == 0 || n == 0) { return max(m, n); }
        
        int dp[m+1][n+1]; dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) { dp[i][0] = i; }
        for (int i = 1; i <= n; ++i) { dp[0][i] = i; }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = min( min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+(word1[i-1] != word2[j-1]) );
            }
        }
        
        return dp[m][n];
    }
};