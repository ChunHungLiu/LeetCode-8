class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> solution;
        int sum = 0;
        sort(num.begin(), num.end());
        combinationSum(num, sum, 0, target, solution, res);
        return res;
    }
    
    void combinationSum(vector<int> &num, int &sum, int level, int target, vector<int> &solution, vector<vector<int> > &res) {
        if (sum > target) { return; }
        if (sum == target) { res.push_back(solution); return; }
        
        for (int i = level; i < num.size(); ++i) {
            sum += num[i];
            solution.push_back(num[i]);
            combinationSum(num, sum, i+1, target, solution, res);
            solution.pop_back();
            sum -= num[i];
            while (i < num.size()-1 && num[i] == num[i+1]) { ++i; }
        }
    }
};