class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() == 0) { return 0; }
        
        unordered_map<int, int> table;
        int res = 1;
        
        for (auto& val : num) {
            if (table[val] != 0) { continue; }
            table[val] = 1;
            int left = table[val-1], right = table[val+1];
            table[val-left] = table[val+right] = 1+left+right;
            res = max(res, 1+left+right);
        }
        
        return res;
    }
};