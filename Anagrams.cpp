class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        vector<string> tmp;
        int n = strs.size();
        if (n == 0) { return res; }
        
        for (int i = 0; i < n; ++i) {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            tmp.push_back(cur);
        }
        
        map<string, int> seen;
        for (int i = 0; i < n; ++i) {
            if (seen.find(tmp[i]) != seen.end()) {
                int idx = seen[tmp[i]];
                if (find(res.begin(), res.end(), strs[idx]) == res.end()) {
                    res.push_back(strs[idx]);
                }
                res.push_back(strs[i]);
            } else {
                seen[tmp[i]] = i;
            }
        }
        
        return res;
    }
};