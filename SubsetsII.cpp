class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int n = S.size();
        int num = pow(2, n);
        vector<vector<int> > res;
        set<vector<int> > seen;
        vector<int> x;
        
        for (int i = 0; i < num; ++i) {
            int cur = i, idx = 0;
            x.clear();
            while (cur > 0) {
                if (cur & 1) {
                    x.push_back(S[idx]);
                }
                ++idx; cur >>= 1;
            }
            sort(x.begin(), x.end(), less<int>());
            if (seen.find(x) == seen.end()) {
                seen.insert(x);
                res.push_back(x);
            }
        }
        
        return res;
    }
};