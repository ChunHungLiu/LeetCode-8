class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);

        for (int i = 1; i <= rowIndex; ++i) {
            int pre = res[0];
            for (int j = 1; j < res.size(); ++j) {
                int oldval = res[j];
                res[j] += pre;
                pre = oldval;
            }
            res.push_back(1);
        }
        
        return res;
    }
};