class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        int dp[len+1];
        bool palin[len][len];
        
        for (int i = 0; i <= len; ++i) { dp[i] = len-i; }
        memset(palin, false, len*len);

        for (int i = len-1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                if (s[i] == s[j] && (j-i < 2 || palin[i+1][j-1])) {
                    palin[i][j] = true;
                    dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        }

        return dp[0]-1;
    }
};