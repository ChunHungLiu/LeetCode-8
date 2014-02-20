class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        if (n == 0 || k == 0 || n < k) { return res; }
        if (n == k) {
            vector<int> x;
            for (int i = 1; i <= n; ++i)
                x.push_back(i);
            res.push_back(x);
            return res;
        } else if (k == 1) {
            vector<int> x;
            x.push_back(1);
            res.push_back(x);
            for (int i = 2; i <= n; ++i) {
                x[0] = i;
                res.push_back(x);
            }
            return res;
        }
        
        vector<vector<int> > r1 = combine(n-1, k);
        for (int i = 0; i < r1.size(); ++i) {
            sort(r1[i].begin(), r1[i].end());
            res.push_back(r1[i]);
        }
        
        vector<vector<int> > r2 = combine(n-1, k-1);
        for (int i = 0; i < r2.size(); ++i) {
            sort(r2[i].begin(), r2[i].end());
            r2[i].push_back(n);
            res.push_back(r2[i]);
        }
        
        return res;
    }
};