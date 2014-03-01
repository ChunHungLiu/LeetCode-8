class Solution {
public:
    // instead of map T to S, map S to T!!!!
    int numDistinct(string S, string T) {
        if (S.size() == 0 || T.size() == 0 || T.size() > S.size()) { return 0; }
        int dp[T.size()+1][S.size()+1];
        dp[0][0] = 1;
        for (int i = 1; i <= T.size(); ++i) dp[i][0] = 0;
        for (int i = 1; i <= S.size(); ++i) dp[0][i] = 1;
        
        for (int i = 1; i <= T.size(); ++i) {
            for (int j = 1; j <= S.size(); ++j) {
                dp[i][j] = dp[i][j-1];
                if (T[i-1] == S[j-1]) { dp[i][j] += dp[i-1][j-1]; }
            }
        }
        
        return dp[T.size()][S.size()];
    }
};

class Solution {
public:
    // instead of map T to S, map S to T!!!!
    int numDistinct(string S, string T) {
        if (S.size() == 0 || T.size() == 0 || T.size() > S.size()) { return 0; }
        int dp[T.size()+1];
        dp[0] = 1;
        for (int i = 1; i <= T.size(); ++i) dp[i] = 0;
        
        for (int i = 1; i <= S.size(); ++i) {
            for (int j = T.size(); j >= 1; --j) {
                if (S[i-1] == T[j-1]) { dp[j] += dp[j-1]; }
            }
        }
        
        return dp[T.size()];
    }
};