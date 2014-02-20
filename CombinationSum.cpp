class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int start, int target) {
        vector<vector<int> > res;
        if (start >= candidates.size() || target < 0) { return res; }
        if (target == 0) {
            vector<int> x;
            res.push_back(x);
            return res;
        }
        
        vector<vector<int> > r1 = combinationSum(candidates, start, target-candidates[start]);
        for (int i = 0; i < r1.size(); ++i) {
            r1[i].insert(r1[i].begin(), candidates[start]);
            res.push_back(r1[i]);
        }
        
        vector<vector<int> > r2 = combinationSum(candidates, start+1, target);
        for (int i = 0; i < r2.size(); ++i) {
            res.push_back(r2[i]);
        }
        
        return res;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
    
        return combinationSum(candidates, 0, target);
    }
};

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        map<int, vector<vector<int> > > dp;
        
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < candidates.size(); ++j) {
                if (candidates[j] > i) { break; }
                else if (candidates[j] == i) {
                    vector<int> x;
                    x.push_back(i);
                    dp[i].push_back(x);
                } else {
                    int diff = i - candidates[j];
                    if (dp.find(diff) == dp.end()) { continue; }
                    else {
                        for (int k = 0; k < dp[diff].size(); ++k) {
                            if (candidates[j] >= dp[diff][k].back()) {
                                vector<int> tmp = dp[diff][k];
                                tmp.push_back(candidates[j]);
                                dp[i].push_back(tmp);
                            }
                        }
                    }
                }
            }
        }
    
        return dp[target];
    }
};