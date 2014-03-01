class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) { return false; }
        if (s1.size() == 0) { return s2 == s3 ? true : false; }
        if (s2.size() == 0) { return s1 == s3 ? true : false; }
        
        vector<vector<bool> > dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= s1.size(); ++i) {
            if (s1[i-1] == s3[i-1]) dp[i][0] = true;
            else { break; }
        }
        for (int i = 1; i <= s2.size(); ++i) {
            if (s2[i-1] == s3[i-1]) dp[0][i] = true;
            else { break; }
        }

        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                int cur = i+j-1;
                if (s1[i-1] == s3[cur]) { dp[i][j] = dp[i-1][j] || dp[i][j]; }
                if (s2[j-1] == s3[cur]) { dp[i][j] = dp[i][j-1] || dp[i][j]; }
            }
        }

        return dp[s1.size()][s2.size()];
    }
};