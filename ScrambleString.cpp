class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) { return false; }
        if (s1.size() == 0 || s1 == s2) { return true; }
        
        int n = s1.size();
        bool s[n][n][n+1];
        
        for (int k = 1; k <= n; ++k) { // k means length
            for (int i = 0; i+k-1 < n; ++i) { 
                for (int j = 0; j+k-1 < n; ++j) {
                    if (k == 1) { s[i][j][k] = (s1[i] == s2[j]); continue; } // init
                    
                    s[i][j][k] = false;
                    for (int l1 = 1; l1 < k; ++l1) {
                        int l2 = k-l1;
                        if ( (s[i][j][l1] && s[i+l1][j+l1][l2]) ||
                             (s[i][j+l2][l1] && s[i+l1][j][l2]) ) {
                                 s[i][j][k] = true;
                                 break;
                        }
                    }
                }
            }
        }
        
        return s[0][0][n];
    }
};