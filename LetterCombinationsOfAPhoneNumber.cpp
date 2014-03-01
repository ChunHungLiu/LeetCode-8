class Solution {
public:
    vector<string> letterCombinations(string& digits, int idx, string cur, map<char, string>& table) {
        vector<string> res;
        if (idx == digits.size()) {
            res.push_back(cur);
            return res;
        }
        
        for (int i = 0; i < table[digits[idx]].size(); ++i) {
            vector<string> r1 = letterCombinations(digits, idx+1, cur+table[digits[idx]][i], table);
            for (int j = 0; j < r1.size(); ++j) {
                res.push_back(r1[j]);
            }
        }
        
        return res;
    }

    vector<string> letterCombinations(string digits) {
        map<char, string> table;
        table['1'] = "";
        table['2'] = "abc";
        table['3'] = "def";
        table['4'] = "ghi";
        table['5'] = "jkl";
        table['6'] = "mno";
        table['7'] = "pqrs";
        table['8'] = "tuv";
        table['9'] = "wxyz";
        table['0'] = " ";
        
        return letterCombinations(digits, 0, "", table);
    }
};