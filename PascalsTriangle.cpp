class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows <= 0) { return res; }
        vector<int> x;
        x.push_back(1);
        res.push_back(x);
        
        for (int i = 1; i < numRows; ++i) {
            x.clear();
            for (int j = 0; j < res[i-1].size(); ++j) {
                if (j == 0) {
                    x.push_back(res[i-1][j]);
                } else {
                    x.push_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
            x.push_back(1);
            res.push_back(x);
        }
        
        return res;
    }
};