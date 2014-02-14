// http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html

// take too long
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = false;
        
        int res_len = 1, res_start = 0;
        for (int i = 0; i < n-1; ++i) {
            dp[i][i] = true;
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                res_len = 2; res_start = i;
            }
        }
        dp[n-1][n-1] = true;
    
        for (int len = 3; len <= n; ++len) {
            for (int start = 0; start < n-len+1; ++start) {
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

// reduce on space
class Solution {
public:
    string helper(string& s, int i, int j) {
        while (i >= 0 && j <= s.size()-1 && s[i] == s[j]) {
            --i; ++j;
        }
        
        return s.substr(i+1, j-i-1);
    }

    string longestPalindrome(string s) {
        if (s.size() == 0) { return ""; }
        int n = s.size();
        
        string res = s.substr(0, 1);
        for (int i = 0; i < n-1; ++i) {
            string s1 = helper(s, i, i);
            if (s1.size() > res.size()) { res = s1; }
            
            string s2 = helper(s, i, i+1);
            if (s2.size() > res.size()) { res = s2; }
        }
        
        return res;
    }
};