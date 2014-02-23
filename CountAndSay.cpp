class Solution {
public:
    string countAndSay(int n) {
        string res = "1", nxt = "";
        
        for (int i = 1; i < n; ++i) {
            char val = res[0];
            int count = 1;
            for (int j = 1; j < res.size(); ++j) {
                if (val == res[j]) { ++count; }
                else {
                    nxt.push_back('0'+count);
                    nxt.push_back(val);
                    val = res[j]; count = 1;
                }
            }
            nxt.push_back('0'+count);
            nxt.push_back(val);
            res = nxt; nxt = "";
        }
        
        return res;
    }
};