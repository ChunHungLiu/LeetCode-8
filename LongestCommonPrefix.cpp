class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res = strs.size() == 0 ? "" : strs[0];
        
        for (int i = 1; i < strs.size(); ++i) {
            int k = 0;
            while (k < strs[i].size()) {
                if (res == "") { return res; }
                if (k == res.size()) { break; }
                if (res[k] != strs[i][k]) { res = strs[i].substr(0, k); break; }
                ++k;
            }
            if (k == strs[i].size()) { res = strs[i]; }
        }
        
        return res;
    }
};