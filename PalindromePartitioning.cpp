class Solution {
public:
    void partition(string&s, vector<vector<string> >& res, vector<string> cur, int idx) {
        if (idx == s.size()) { res.push_back(cur); return; }
        
        for (int i = 1; i <= s.size()-idx; ++i) {
            if (valid(s, idx, i)) {
                cur.push_back(s.substr(idx, i));
                partition(s, res, cur, idx+i);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> cur;
        partition(s, res, cur, 0);
        return res;
    }
    
    bool valid(string& s, int start, int len) {
        if (len <= 1) { return true; }
        int end = start+len-1;
        while (start < end && s[start] == s[end]) { ++start; --end; }
        return end <= start;
    }
};