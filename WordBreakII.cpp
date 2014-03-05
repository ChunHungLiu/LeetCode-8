// same idea, don't know why gives a time limit exceeded error
class Solution {
public:
    void wordBreak(string &s, vector<vector<int>> &valid, int start, string path, vector<string> &res) {
        for (auto len : valid[start]) {
            string newPath = path;
            if (start != 0) { newPath += (" "+s.substr(start, len)); }
            else { newPath += s.substr(start, len); }
            if (start+len == s.size()) { res.push_back(newPath); }
            else { wordBreak(s, valid, start+len, newPath, res); }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0) { return vector<string>(); }
        int n = s.size();
        vector<vector<int> > valid(n, vector<int>());
        
        for (int start = 0; start < n; ++start) {
            for (int len = 1; len <= n-start; ++len) {
                string tmp = s.substr(start, len);
                if (dict.find(tmp) != dict.end()) { valid[start].push_back(len); }
            }
        }
        
        vector<string> res;
        if (valid[0].size() == 0) { return res; }
        wordBreak(s, valid, 0, "", res);
        
        return res;
    }
};