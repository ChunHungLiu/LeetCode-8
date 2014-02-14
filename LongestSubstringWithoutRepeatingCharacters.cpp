class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n+1][n+1];
        
        // init to all false    
        for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = false;

        // get len = 1
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
            
        int res_len = 1, res_start = 0;
        // get len = 2
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                res_len = 2; res_start = i;
            }
        }
    
        // increase length and see
        for (int len = 3; len <= n; ++len) {
            for (int start = 0; start < n-start+1; ++start) {
                int end = start+len-1;
                if (s[start] == s[end] && dp[start+1][end-1]) {
                    dp[start][end] = true;
                    res_len = len; res_start = start;
                }
            }
        }
        
        return s.substr(res_start, res_len);
    }
};