class Solution {
public:
    vector<string> generateParenthesis(string cur, int left, int right, int n) {
        vector<string> res;
        if (n == 0 || right > left || left > n || right > n) { return res; }
        if (left == n && right == n) {
            res.push_back(cur);
            return res;
        } 
        vector<string> r1 = generateParenthesis(cur+"(", left+1, right, n);
        vector<string> r2 = generateParenthesis(cur+")", left, right+1, n);
        for (int i = 0; i < r1.size(); ++i) 
            res.push_back(r1[i]);
        for (int i = 0; i < r2.size(); ++i)
            res.push_back(r2[i]);

        return res;
    }

    vector<string> generateParenthesis(int n) {
        return generateParenthesis("", 0, 0, n);
    }
};