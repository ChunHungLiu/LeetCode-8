class Solution {
public:
    bool next(vector<int> &num) {
        if (num.size() <= 1) { return false; }
        
        int i = num.size()-2;
        while (i >= 0 && num[i] >= num[i+1]) { --i; }
        if (i < 0) { return false; }
        
        int j = num.size()-1;
        while (j > i && num[j] <= num[i]) { --j; }
        
        swap(num[i], num[j]);
        reverse(num.begin()+i+1, num.end());
        
        return true;
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        if (num.size() == 0) { return res; }
        
        sort(num.begin(), num.end());
        
        res.push_back(num);
        while(next(num)) {
            res.push_back(num);
        }
        
        return res;
    }
};