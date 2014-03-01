class Solution {
public:
    bool valid(string& s) {
        int val = atoi(s.c_str());
        return (val == 0 && s.size() == 1) || (val > 0 && val < 256 && s[0] != '0');
    }
    
    vector<string> restoreIpAddresses(string s, int n) {
        vector<string> res;
        if (n == 1) {
            if (valid(s)) { res.push_back(s); }
            return res;
        }
        if (s.size() < n || s.size() > n*3) { return res; }
        
        for (int i = 0; i < 3; ++i) {
            if (i == s.size()) { return res; }
            string head = s.substr(0, i+1);
            if (valid(head)) {
                vector<string> r1 = restoreIpAddresses(s.substr(i+1), n-1);
                for (auto j : r1) { res.push_back(head+'.'+j); }
            }
        }
        
        return res;
    }

    vector<string> restoreIpAddresses(string s) {
        return restoreIpAddresses(s, 4);
    }
};